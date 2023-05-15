#include "dotold.h"
#include "qgraphicsproxywidget.h"
#include "qpainter.h"
#include"pin.h"
#include<QColor>
#include<QGraphicsScene>
#include <QOpenGLPaintDevice>

dotold::~dotold()
{
    for(int i=0;i<whires.count();i++)
    {

        delete whires[i];
    }
}

dotold::dotold(Pin* p, QThread* thr)
{
    if (thr != nullptr)
        moveToThread(thr);
    setZValue(5);
    pin=p;
    pin->parCon->graphicsProxyWidget()->scene()->addItem(this);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsFocusable,true);

}

void dotold::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter = new QPainter(new QOpenGLPaintDevice());
    painter->setPen(QPen(color));
    painter->setBrush(QBrush(color));
    painter->drawPath(shape());
}

QRectF dotold::boundingRect() const
{
    return shape().boundingRect();
}

QPainterPath dotold::shape() const
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

qreal dotold::x()
{
    qreal res= scenePos().x();
    return res;
}

void dotold::x(int x)
{
    setPos(x,scenePos().y());
}

qreal dotold::y()
{
    return scenePos().y();

}

void dotold::y(int y)
{
    setPos(scenePos().x(),y);
}

void dotold::Uupdate(bool collision, QVector<dotold*>* nnot)
{
    y(pin->y());
    for (int i = 0; i < whires.count(); i++)
    {
        whires[i]->updateShape(collision);
    }
    nnot->append(this);
    for (int i = 0; i < verticalMove.count(); i++)
    {
        if (!nnot->contains(verticalMove[i]))
        {
            verticalMove[i]->x(x());
            verticalMove[i]->Uupdate(collision, nnot);
        }
    }
    
    pin->PinWUpd();
    if(collision)
    {
        pin->getpinWhire()->FixColliding();
    }
}


void dotold::AddWhire(Whire *w)
{
    
    pin->pinWhire();
    whires.append(w);
}

void dotold::RemoveWhire(Whire *w)
{
    if (whires.removeOne(w))
    {
        if (whires.isEmpty())
        {
            for (int i = 0; i < verticalMove.count(); i++)
            {
                try {
                    verticalMove[i]->verticalMove.removeOne(this);
                }
                catch(...)
                {

                }
            }
            verticalMove.clear();
            pin->pinWhire(false);
        }
        else
        {

        }
    }
}

void dotold::AddDot(dotold *w)
{
    verticalMove.append(w);
}

void dotold::RemoveDot(dotold *w)
{
    verticalMove.removeOne(w);
}


int dotold::type() const
{
    return 100;
}
