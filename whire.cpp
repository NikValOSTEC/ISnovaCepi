#include "whire.h"
#include "qgraphicsproxywidget.h"
#include "qgraphicsscene.h"
#include "qpainter.h"

Whire::Whire(Pin* p1,Pin*p2)
{
    if(p1->chain==nullptr&&p2->chain==nullptr)
        chain = new Chain();
    else if (p2->chain != nullptr)
    {
        chain = p2->chain;
    }
    else
    {
        chain = p1->chain;
    }
    this->p1=p1;
    this->p2=p2;
    p1->Dot()->AddWhire(this);
    p2->Dot()->AddWhire(this);
    p1->Dot(true);
    p2->Dot(true);
    p2->Dot(p1->Dot());
    p1->parCon->graphicsProxyWidget()->scene()->addItem(this);
    p1->Update();
    p2->Update();
    p1->Dot()->AddDot(p2->Dot());
    p2->Dot()->AddDot(p1->Dot());
    p1->pinWhire();
    p2->pinWhire();
    chain->AddPin(p1);
    chain->AddPin(p2);
}
QRectF Whire::boundingRect() const
{
    return shape().boundingRect();
}

QPainterPath Whire::shape() const
{
    return patt;
}

void Whire::updateShape(bool colision)
{
    patt=QPainterPath();
    patt.moveTo(p1->Dot()->x(),p1->Dot()->y());
    patt.lineTo(p2->Dot()->x(),p2->Dot()->y());
    if(colision)
        CollisionFix();
}

void Whire::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen( QPen(Qt::red, 5));
    painter->drawPath(shape());
}

Whire::~Whire()
{
    p1->Dot()->RemoveWhire(this);
    p2->Dot()->RemoveWhire(this);
}

void Whire::CollisionFix()
{
    bool recur=false;

    QList<QGraphicsItem*>list = collidingItems();

    foreach (QGraphicsItem* gi, list) {
        ProxyRectPort * itemPort= dynamic_cast<ProxyRectPort *>(gi);
        if(itemPort)
        {
            qDebug() << p1->Dot()->x() << "  " << itemPort->XX();
            move(p1->Dot()->x()>itemPort->XX(),50);
            recur=true;
        }
        else
        {
            Whire* itemWh=dynamic_cast<Whire *>(gi);
            if(itemWh)
            {
                move(true,5);
                itemWh->move(false,5);
                itemWh->CollisionFix();
                recur=true;
            }
        }
    }

    if(recur)
        this->CollisionFix();
}

void Whire::move(bool left_rigth, int x)
{
    if(!left_rigth)
        p1->Dot()->x(p1->Dot()->x()-x);
    else
        p1->Dot()->x(p1->Dot()->x()+x);
    p1->Dot()->Uupdate();
}
