#include "proxyrectport.h"
#include"port.h"
#include"NewWhire.h"
#include<qthread.h>

ProxyRectPort::ProxyRectPort(Port*port)
{

    setZValue(1);
    port->proxy(this);
    this->port=port;
    this->colo=QColor(122,295,15);

    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsFocusable,true);
}

void ProxyRectPort::EmitMove()
{
    emit strartMove();
    disconnect(this, SIGNAL(strartMove()), nullptr, nullptr);
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

void ProxyRectPort::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    if (isSelected())
        painter->setBrush(QBrush(QColor(137, 224, 8)));
    else
        painter->setBrush(QBrush(QColor(122, 195, 15)));
    painter->drawRect(boundingRect());
}


QRectF ProxyRectPort::geometry()
{
    return rect;
}

void ProxyRectPort::geometry(QRectF rec)
{
    int x = rec.x();
    int y = rec.y();
    x = floor(x / 25) * 25;
    y = floor(y / 25) * 25;
    int w = rec.width();
    int h = rec.height();
    w = floor(w / 25) * 25;
    h = floor(h / 25) * 25;
    rect=rec;
    rect.setX(x);
    rect.setY(y);
    rect.setWidth(w);
    rect.setHeight(h);
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

void ProxyRectPort::Update(bool upd)
{

    this->port->Update(upd);
    if (upd)
    {
        int x = floor(scenePos().x() / 25) * 25;
        int y = floor(scenePos().y() / 25) * 25;
        setPos(x, y);
        
        EmitMove();
        QThread::msleep(100);
        ColiderCheck();
    }
}

int ProxyRectPort::type() const
{
    return 101;
}

void ProxyRectPort::ColiderCheck(bool upd)
{

    QList<QGraphicsItem *> list = scene()->collidingItems(this,Qt::IntersectsItemBoundingRect);
    foreach(QGraphicsItem * i , list)
    {
        
        if (CustomColliderLineRecoursive* item = dynamic_cast<CustomColliderLineRecoursive*>(i))
        {
            if (upd)
            {
                item->FixColliding();
            }
        }
        else if (NewWhire* item = dynamic_cast<NewWhire*>(i))
        {

            item->FixColliding();
        }

    }

}

qreal ProxyRectPort::XX()
{
    return this->mapToScene(boundingRect().topLeft()).x();
}

qreal ProxyRectPort::YY()
{
    return this->mapToScene(boundingRect().topLeft()).y();
}

void ProxyRectPort::XX(qreal x)
{
    this->rect.moveCenter(mapFromScene(x, mapToScene(rect.center()).y()));
}
void ProxyRectPort::YY(qreal y)
{
    this->rect.moveCenter(mapFromScene(mapToScene(rect.center()).x(), y));
}
