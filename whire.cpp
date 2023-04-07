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
    patt = QPainterPath();
    patt.moveTo(p1->Dot()->x(), p1->Dot()->y());
    patt.lineTo(p2->Dot()->x(), p2->Dot()->y());
}
QRectF Whire::boundingRect() const
{
    QPainterPath pabou = QPainterPath();
    pabou.moveTo(p1->Dot()->x(),p1->Dot()->y());
    pabou.lineTo(p2->Dot()->x(),p2->Dot()->y());
    return pabou.boundingRect();
}

QPainterPath Whire::shape() const
{
    return patt;
}

void Whire::updateShape(bool colision)
{
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
    bool recur = false;

    QList<QGraphicsItem*>list = collidingItems(Qt::IntersectsItemBoundingRect);
    QList<ProxyRectPort*>ports = QList<ProxyRectPort*>();
    QList<Whire*>whires = QList<Whire*>();
    QList<PinLineColision*>pinlines = QList<PinLineColision*>();

    foreach(QGraphicsItem * gi, list) {
        if (ProxyRectPort* itemPort = dynamic_cast<ProxyRectPort*>(gi))
        {
            //ports.append(itemPort);
        }
        else if (Whire* itemWh = dynamic_cast<Whire*>(gi))
        {
            whires.append(itemWh);
        }
        else if (PinLineColision* itemCol = dynamic_cast<PinLineColision*>(gi))
        {
            if (itemCol->p1->chain != p1->chain && itemCol->p1->chain != p2->chain)
            {
                pinlines.append(itemCol);
            }
        }
    }

    for (int i = 0; i < ports.count(); i++)
    {
        //move(p1->Dot()->x() > ports[i]->XX(), 50);
    }
    bool mv = false;
    for (int i = 0; i < whires.count(); i++)
    {

        if (whires[i]->chain != chain)
        {
            whires[i]->move(false, 5);
            mv = true;
        }
    }

    if (mv)
    {
        move(true, 5);
    }
    std::sort(pinlines.begin(), pinlines.end(),
        [](const PinLineColision* a, const PinLineColision* b) -> bool { return a->boundingRect().top() < b->boundingRect().top(); });
    patt = QPainterPath();
    Pin* top, * bottom;
    if (p1->y() < p2->y())
    {
        top = p1;
        bottom = p2;
    }
    else
    {
        top = p2;
        bottom = p1;
    }

    patt.moveTo(top->Dot()->x(), top->Dot()->y());

    for (int i = 0; i < pinlines.count(); i++)
    {
        patt.lineTo(top->Dot()->x(), pinlines[i]->y() - 15);
        patt.moveTo(top->Dot()->x(), pinlines[i]->y() - 15);
        patt.arcTo(top->Dot()->x() - 15, pinlines[i]->y() - 15, 30, 30, 90, 180);
        patt.moveTo(top->Dot()->x(), pinlines[i]->y() + 15);
    }
    patt.lineTo(bottom->Dot()->x(), bottom->Dot()->y());


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
