#include "proxyrectport.h"
#include<QDebug>

ProxyRectPort::ProxyRectPort(Port*port)
{
    port->proxy(this);
    this->port=port;
    this->colo=QColor(122,295,15);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsFocusable,true);
}
QPainterPath ProxyRectPort::shape() const
{
    QPainterPath path=QPainterPath();
    path.addRect(rect);
    return path;
}

QRectF ProxyRectPort::boundingRect() const
{

    return rect;
}

void ProxyRectPort::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::blue));
    painter->drawRect(rect);
}


QRectF ProxyRectPort::geometry()
{
    return rect;
}

void ProxyRectPort::geometry(QRectF rec)
{
    rect=rec;
}

void ProxyRectPort::setconnector(Port *port)
{
    this->port=port;
}

Port *ProxyRectPort::getport()
{
    return port;
}

QColor ProxyRectPort::color()
{
    return colo;
}

void ProxyRectPort::color(QColor c)
{
    this->colo=c;
}

ProxyRectPort::~ProxyRectPort()
{

}

void ProxyRectPort::Update()
{
    this->port->Update();
    ColiderCheck();
}

int ProxyRectPort::type() const
{
    return 101;
}

void ProxyRectPort::ColiderCheck()
{

    QList<QGraphicsItem *> list = collidingItems(Qt::IntersectsItemBoundingRect);
    qDebug() << "CollisionFix" << list.length();
    foreach(QGraphicsItem * i , list)
    {
        
        if (PinLineColision* item = dynamic_cast<PinLineColision*>(i))
        {
            item->FixColliding();
        }
        else if (Whire* item = dynamic_cast<Whire*>(i))
        {
            item->CollisionFix();
        }

    }

}

qreal ProxyRectPort::XX()
{
    return this->mapToScene(rect.center()).x();
}

qreal ProxyRectPort::YY()
{
    return this->mapToScene(rect.center()).y();
}
