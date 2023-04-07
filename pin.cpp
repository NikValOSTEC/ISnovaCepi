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
    pinW = new PinLineColision(this);
    port->graphicsProxyWidget()->scene()->addItem(pinW);
    pinWhire(false);    
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)),
        this, SLOT(showContextMenu(QPoint)));
    chain = nullptr;
}

Pin::~Pin()
{
    try
    {
        delete(d);
        delete(pinW);
    }
    catch (...)
    {

    }
    delete ui;
}

void Pin::Update()
{
    d->Uupdate();
    PinWUpd();
    pinW->FixColliding();
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
            auto w = new Whire(fpin, this);
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
        d = new dot(this);
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
    return myMenu;
}

void Pin::RemoveFromChain()
{
    chain->RemovePin(this);
}

void Pin::showContextMenu(const QPoint& pos)
{
    QPoint globalPos = this->mapToGlobal(pos);
    ContextMenu()->exec(globalPos);
}
