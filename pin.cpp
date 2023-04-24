#include "pin.h"
#include "ui_pin.h"
#include "whire.h"
#include<QLineEdit>
#include<QGraphicsProxyWidget>
#include<QPoint>
#include<QPointF>
#include<QDrag>
#include<QMimeData>
#include<QGraphicsScene>

Pin::Pin(Port* port, QLineEdit* parent) :
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
    pinW = new PinLineColision(this, thread);    
    port->graphicsProxyWidget()->scene()->addItem(pinW);
    pinWhire(false);
    connect(this, &Pin::updSignal, this, &Pin::Update);
}

Pin::~Pin()
{
    RemoveFromChain();
    delete(d);
    delete(pinW);
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



void Pin::Update()
{
    d->Uupdate(true);
    PinWUpd();
    pinW->FixColliding();
}


void Pin::EmitUpd()
{
    emit updSignal();
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
        if (fpin != this)
        {
            AddWhireCommand(fpin, this);
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

dot* Pin::Dot(bool recalc)
{
    if (d == nullptr)
    {
        d = new dot(this,thread);
    }
    if (recalc)
    {
        QPointF point = QPointF();
        point = mapTo(parCon, QPoint(this->width() / 2, this->height() / 2));
        point = this->parCon->graphicsProxyWidget()->mapToScene(point);
        d->setPos(point);
    }
    return d;
}

dot* Pin::Dot(dot* dot)
{
    if (d == nullptr)
    {
        Dot(true);
    }
    d->x(d->x() - (d->x() - dot->x()) / 2);
    dot->x(d->x());
    return d;

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
        pinW->hide();
        d->hide();
    }
    else
    {
        pinW->updateShape();
        pinW->show();
        d->show();
    }
}

void Pin::PinWUpd()
{
    pinW->updateShape();
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
    delete this;
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
