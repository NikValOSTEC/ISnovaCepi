#include "dot.h"
#include "qgraphicsproxywidget.h"
#include "qpainter.h"
#include"pin.h"
#include<QColor>
#include<QGraphicsScene>

dot::~dot()
{
    for(int i=0;i<whires.count();i++)
    {
        delete whires[i];
    }
}

dot::dot(Pin* p)
{
    setZValue(5);
    pin=p;
    pin->parCon->graphicsProxyWidget()->scene()->addItem(this);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsFocusable,true);

}

void dot::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(color));
    painter->setBrush(QBrush(color));
    painter->drawPath(shape());
}

QRectF dot::boundingRect() const
{
    return shape().boundingRect();
}

QPainterPath dot::shape() const
{
    QPainterPath path;
    if(Big)
    {
        path.addEllipse(-10,-10,20,20);
    }
    else
    {
        path.addEllipse(-5,-5,10,10);
    }
    return path;
}

qreal dot::x()
{
    qreal res= scenePos().x();
    return res;
}

void dot::x(int x)
{
    setPos(x,scenePos().y());
}

qreal dot::y()
{
    return scenePos().y();

}

void dot::y(int y)
{
    setPos(scenePos().x(),y);
}

void dot::Uupdate(bool collision, QVector<dot*>* nnot)
{
    nnot->append(this);
    y(pin->y());
    for(int i=0;i<whires.count();i++)
    {
        whires[i]->updateShape(collision);
    }
    for(int i=0;i<verticalMove.count();i++)
    {
        if(!nnot->contains(verticalMove[i]))
        {
            verticalMove[i]->x(x());
            verticalMove[i]->Uupdate(collision,nnot);
        }
    }
    pin->PinWUpd();
}


void dot::AddWhire(Whire *w)
{
    
    pin->pinWhire();
    whires.append(w);
}

void dot::RemoveWhire(Whire *w)
{
    if (whires.removeOne(w))
    {
        if (whires.isEmpty())
        {
            for (int i = 0; i < verticalMove.count(); i++)
            {
                verticalMove[i]->verticalMove.removeOne(this);
            }
            verticalMove.clear();
        }
    }
}

void dot::AddDot(dot *w)
{
    verticalMove.append(w);
}

void dot::RemoveDot(dot *w)
{
    verticalMove.removeOne(w);
}


int dot::type() const
{
    return 100;
}
