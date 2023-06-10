#include "Pin.h"
#include "port.h"
#include "NewPinWhire.h"
#include "AddPinComand.h"
#include "chain.h"
#include "Dot.h"
#include<qdrag.h>
#include<qmimedata.h>
#include"AddWhireCommand.h"
#include"proxyrectport.h"
#include"RemovePinCommand.h"
Pin::Pin(Port* port, bool bl, QLineEdit* parent) :
    QLineEdit(parent),
    ui(new Ui::Pin)
{
    ui->setupUi(this);
    parCon = port;
    d = nullptr; 
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)),
        this, SLOT(showContextMenu(QPoint)));
    chain = nullptr;
    thread = new QThread();
    moveToThread(thread);
    command = nullptr;
    cored = nullptr;

    if (bl)
    {
        d = new Dot();
        port->graphicsProxyWidget()->scene()->addItem(d);
        pinW = new NewPinWhire(this, thread);
        port->graphicsProxyWidget()->scene()->addItem(pinW);
        pinWhire(false);
        connect(this, &Pin::updSignal, this, &Pin::Update);
    }
    else
    {
        d = nullptr;
        pinW = nullptr;
        cored = nullptr;
    }
    setFixedHeight(19);
}



Pin::~Pin()
{
    RemoveFromChain();
    if (pinW != nullptr)
        delete(pinW);
}

int Pin::index()
{
    return parCon->pins().indexOf(this);
}

const QString Pin::name()
{
    return text();
}

void Pin::name(QString name)
{
    this->setText(name);
    _name = name;
}



void Pin::Update(bool upd)
{
    PinWUpd();
}


void Pin::EmitUpd(bool dotold)
{
    if (dotold&&chain!=nullptr)
    {
        chain->Dots();
    }
    upd = dotold;
    emit updSignal(true);
}

NewPinWhire* Pin::getpinWhire()
{
    return pinW;
}

void Pin::mousePressEvent(QMouseEvent* event)
{
    if ((event->button() == Qt::LeftButton))
    {
        if (event->modifiers() & Qt::SHIFT)
        {

        }
        else
        {
            QDrag* drag = new QDrag(this);
            QMimeData* mimeData = new QMimeData();
            uintptr_t adress = (uintptr_t)this;
            QString str = QString::number(adress);
            mimeData->setData("Pin", str.toUtf8());
            drag->setMimeData(mimeData);
            Qt::DropAction dropAction = drag->exec();
        }
        event->accept();
    }
}

void Pin::dragEnterEvent(QDragEnterEvent* event)
{
    if (event->mimeData()->hasFormat("Pin"))
    {
        event->accept();
    }
    else
        event->ignore();
}

void Pin::dropEvent(QDropEvent* event)
{
    if (event->mimeData()->hasFormat("Pin"))
    {
        QVariant var = QVariant::fromValue(QString::fromUtf8(event->mimeData()->data("Pin")));
        uintptr_t address = var.value<uintptr_t>();
        Pin* fpin = (Pin*)address;
        if (fpin->chain != chain || chain==nullptr)
        {
            if (fpin != this)
            {
                new AddWhireCommand(fpin->command, this->command);
                fpin->pinWhire();
                this->pinWhire();
            }
        }
    }
    else
        event->ignore();
}

void Pin::dragMoveEvent(QDragMoveEvent* event)
{
    if (event->mimeData()->hasFormat("Pin"))
    {
        event->accept();
    }
    else
        event->ignore();
}

Dot* Pin::dot(bool recalc)
{
    return d;
}





void Pin::dot(Dot* dt)
{
    d = dt;
}

Dot* Pin::coredot()
{
    if (cored==nullptr)
    {
        cored = new Dot();
        parCon->proxy()->scene()->addItem(cored);

    }
    return cored;
}

qreal Pin::x()
{
    return this->parCon->graphicsProxyWidget()->mapToScene(mapTo(parCon, QPoint(this->width() / 2, this->height() / 2))).x();
}

qreal Pin::y()
{
    return this->parCon->graphicsProxyWidget()->mapToScene(mapTo(parCon, QPoint(this->width() / 2, this->height() / 2))).y();
}

void Pin::pinWhire(bool show)
{
    if (!show)
    {
        pinW->ClearInside();
        pinW->hide();
        d->hide();
    }
    else
    {
        //emit dot
        pinW->show();
        d->show();
        pinW->FixColliding();
    }
}

void Pin::PinWUpd()
{
    if (d->pos().x()>this->x())
    {
        cored->setX(parCon->proxy()->mapToScene(parCon->proxy()->boundingRect().topRight()).x());
        cored->setY(y());
    }
    else
    {
        cored->setX(parCon->proxy()->mapToScene(parCon->proxy()->boundingRect().topLeft()).x());
        cored->setY(y());
    }
    cored->Emit_Moving();
    //pinW->ClearInside();
}

QMenu* Pin::ContextMenu()
{

    QMenu* myMenu = new QMenu();
    myMenu->addAction("RemoveFromChain", this, SLOT(RemoveFromChain()));
    myMenu->addAction("Remove", this, SLOT(Remove()));
    myMenu->addAction("Color", this, SLOT(ChangeColor()));

    return myMenu;
}

void Pin::RemoveFromChain()
{
    try {
        if(chain!=nullptr)
            chain->RemovePin(this);
    }
    catch(_exception ex)
    {

    }
}

void Pin::Remove()
{
    new RemovePinCommand(this);
}

void Pin::ChangeColor()
{
    if (chain == nullptr)
        return;
    bool ok;
    QColor olor = QColorDialog::getColor(chain->color);
    if (&ok)
        chain->color = QColor(olor);
}

void Pin::showContextMenu(const QPoint& pos)
{
    QPoint globalPos = this->mapToGlobal(pos);
    ContextMenu()->exec(globalPos);
}
