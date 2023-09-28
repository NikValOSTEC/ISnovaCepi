#include "proxyrectport.h"
#include"port.h"
#include"NewWhire.h"
#include<qthread.h>
#include "MessageHandler.h"

ProxyRectPort::ProxyRectPort(Port*port)
{

    setZValue(1);
    port->proxy(this);
    this->port=port;
    this->colo=QColor(122,295,15);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsFocusable,true);
    myMessageHandler( "ProxyRectPort");
}

void ProxyRectPort::EmitMove()
{
    emit strartMove();
}
void ProxyRectPort::DeleteLater()
{
    deleteLater();
}
QPainterPath ProxyRectPort::shape() const
{
    QPainterPath path = QPainterPath();
    try 
    {
        path.addRect(QRectF(0, 0, port->width(), port->height() + 25));
    }
    catch (_exception ex)
    {

    }
    return path;
}

QRectF ProxyRectPort::boundingRect() const
{
    return shape().boundingRect();
}

void ProxyRectPort::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    if (isSelected())
        painter->setBrush(QBrush(QColor(137, 224, 8)));
    else
        painter->setBrush(QBrush(QColor(122, 195, 15)));
    painter->drawPath(shape());
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
    QGraphicsItem::prepareGeometryChange();
    hide();
    EmitMove();
    delete(port);
    myMessageHandler( "~ProxyRectPort");
}

void ProxyRectPort::Update(bool upd,int i)
{
    if (i > 4)
    {
        int x = floor(scenePos().x() / 25) * 25+50;
        int y = floor(scenePos().y() / 25) * 25+50;
        setPos(x, y);
    }
    int x = left()-25;
    int y = top()-25;
    int w = this->boundingRect().width()+25;
    int h = this->boundingRect().height()+25;
    QList<QGraphicsItem*> list = scene()->items(x, y, w, h, Qt::IntersectsItemBoundingRect, Qt::DescendingOrder);
    foreach(auto prx, list)
    {
        try {
            if (ProxyRectPort* prp = dynamic_cast<ProxyRectPort*>(prx))
            {
                if (prp != this)
                {
                    ProxyColider();
                }
            }
        }
        catch(...)
        {

            int x = floor(scenePos().x() / 25) * 25;
            int y = floor(scenePos().y() / 25) * 25;
            this->Update(upd,i++);

        }
    }
    int xx = floor(scenePos().x() / 25) * 25;
    int yy = floor(scenePos().y() / 25) * 25;
    setPos(xx, yy);
    this->port->Update();
    if (upd)
    {
        EmitMove();
        QThread::msleep(100);
        ColiderCheck();
    }
    myMessageHandler( "ProxyRectPortUpdate");
}

int ProxyRectPort::type() const
{
    return 101;
}

void ProxyRectPort::ColiderCheck(bool upd)
{

    int x = left();
    int y = top();
    int w = this->boundingRect().width();
    int h = this->boundingRect().height();
    QList<QGraphicsItem*> list = scene()->items(x, y, w, h, Qt::IntersectsItemBoundingRect, Qt::DescendingOrder);
    QList<CustomColliderLineRecoursive*> post = QList<CustomColliderLineRecoursive*>();

    if (upd) {
        bool fx = true;
        foreach(QGraphicsItem * i, list)
        {

            if (CustomColliderLineRecoursive* item = dynamic_cast<CustomColliderLineRecoursive*>(i))
            {
                if (item->Vertical_f_Horizontal_t)
                {
                    item->FixColliding();
                    fx = false;

                }
                else
                {
                    post.append(item);
                }
            }
        }
        if (fx)
        {

            foreach(CustomColliderLineRecoursive * j, post)
            {
                j->FixColliding();
            }
        }
    }
    myMessageHandler( "ProxyRectPortColliderCheck");


}

void ProxyRectPort::ProxyColider(int xx, int yy)
{
    int x = left()-25;
    int y = top()-25;
    int w = this->boundingRect().width()+50;
    int h = this->boundingRect().height()+50;
    QList<QGraphicsItem*> list = scene()->items(x, y, w, h, Qt::IntersectsItemBoundingRect, Qt::DescendingOrder);
    foreach (auto prx, list)
    {
        if (ProxyRectPort* prp = dynamic_cast<ProxyRectPort*>(prx)) 
        {
            if (prp != this)
            {
                if (xx == 0 && yy == 0)
                {
                    if (prp->center().y() < this->center().y())
                    {
                        YY(prp->YY() + this->boundingRect().height());
                        yy = 1;
                    }
                    else
                    {
                        YY(prp->top() - this->boundingRect().height());
                        yy = -1;
                    }

                    if (prp->center().x() < this->center().x())
                    {
                        XX(prp->right() + boundingRect().width());
                        xx = 1;
                    }
                    else
                    {
                        XX(prp->left() - this->boundingRect().width());
                        xx = -1;
                    }
                }
                else
                {
                    YY(YY() + (yy * 50));
                    XX(XX() + (xx * 50));
                }
                ProxyColider(xx, yy);
                break;
            }
        }
    }
    myMessageHandler( "ProxyRectPortCollider(x,y)");
}

qreal ProxyRectPort::XX()
{
    return scenePos().x();
}

qreal ProxyRectPort::YY()
{
    return scenePos().y();
}

void ProxyRectPort::XX(qreal x)
{
    this->setPos(x, YY());
}
void ProxyRectPort::YY(qreal y)
{
    this->setPos(XX(), y);
}
