#include "pinlinecolision.h"
#include "qpainter.h"
#include<QtAlgorithms>>
#include"qgraphicsscene.h"

qreal PinLineColision::y()
{
    return p1->y();
}

QRectF PinLineColision::boundingRect() const
{
    auto rect = QRectF();
    rect.setTop(Dot->y() - 2);
    rect.setBottom(Dot->y() + 2);
    if (Dot->x() < p1->x())
    {
        rect.setLeft(Dot->x());
        rect.setRight(p1->x() - p1->width() / 2);
    }
    else
    {
        rect.setLeft(Dot->x());
        rect.setRight(p1->x() + p1->width() / 2);
    }
    return rect;
    //return shape().boundingRect();
}

QPainterPath PinLineColision::shape() const
{
    return patt;
}

void PinLineColision::updateShape()
{

    prepareGeometryChange();
    patt=QPainterPath();
    patt.moveTo(Dot->x(),Dot->y());
    if(Dot->x()<p1->x())
        patt.lineTo(p1->x()-p1->width()/2,p1->y());
    else
        patt.lineTo(p1->x()+p1->width()/2,p1->y());
}

void PinLineColision::FixColliding()
{


    bool left_rigth=true;
    QList<QGraphicsItem*> list = collidingItems(Qt::IntersectsItemBoundingRect);
    patt=QPainterPath();
    qDebug() << "lst: " << list.length();
    QList<ProxyRectPort*> proxys= QList<ProxyRectPort*>();
     if(Dot->x()<p1->x())
     {
         left_rigth=false;
     }
    foreach(QGraphicsItem * i, list)
    {
        ProxyRectPort * item= dynamic_cast<ProxyRectPort *>(i);
        if (item)
        {
            bool add = true;
            auto dt=item->mapToScene(item->boundingRect().topLeft());
            if((item!=p1->parCon->proxy()))
            {
                foreach(auto w, p1->Dot()->whires)
                {
                    if (w->p1->parCon->proxy() == item || w->p2->parCon->proxy() == item)
                    {
                        add = false;
                    }
                }                
                
            }
            else
            {
                add = false;
            }
            if (add)
            {
                proxys.append(item);
            }
        }
    }
    std::sort(proxys.begin(), proxys.end(),
          [](const ProxyRectPort* a, const ProxyRectPort* b) -> bool { return a->mapToScene(a->boundingRect().topLeft()).x() < b->mapToScene(b->boundingRect().topLeft()).x(); });



    if(!left_rigth)
    {
        qreal left, bottom, right, y = p1->Dot()->y(), lastx = p1->Dot()->x();
        patt.moveTo(lastx, y);
        pattest = QPainterPath();
        foreach(auto prox, proxys)
        {
            
            bool reWhider = true;

            left = prox->mapToScene(prox->boundingRect().left(), 0).x();
            right = prox->mapToScene(prox->boundingRect().right(), 0).x();
            bottom = prox->mapToScene(0, prox->boundingRect().bottom()).y();
            QPainterPath pathpart = QPainterPath();
            int tms = 0;
            int oldtms = 0;
            while (reWhider)
            {
                tms = 0;
                pathpart = QPainterPath();
                pathpart.moveTo(left - (oldtms+1) * 20, y);
                pathpart.lineTo(left- (oldtms+1) * 20, bottom+ (oldtms+1) * 20);
                pathpart.lineTo(right+ (oldtms+1) * 20, bottom+ (oldtms+1) * 20);
                pathpart.lineTo(right+ (oldtms+1) * 20, y);
                pattest.addRect(pathpart.boundingRect());
                pattest.addPath(pathpart);
                auto lst = scene()->items(pathpart.boundingRect(), Qt::IntersectsItemBoundingRect);
                reWhider = false;
                foreach(auto i, lst)
                {
                    PinLineColision* x = dynamic_cast<PinLineColision*>(i);
                    if (x)
                    {
                        if (x != this&&x->collidesWithItem(prox,Qt::IntersectsItemBoundingRect))
                        {
                            tms += 1;
                        }
                    }
                }
                if (oldtms < tms)
                {
                    reWhider = true;
                    oldtms = tms;
                }

            }          
            pathpart = QPainterPath();
            pathpart.moveTo(lastx, y);
            pathpart.lineTo(left - (oldtms + 1) * 15, y);
            pathpart.lineTo(left - (oldtms + 1) * 15, bottom + (oldtms + 1) * 15);
            pathpart.lineTo(right + (oldtms + 1) * 15, bottom + (oldtms + 1) * 15);
            pathpart.lineTo(right + (oldtms + 1) * 15, y);
            patt.addPath(pathpart);
            lastx = right + (oldtms + 1) * 15;
        }
        patt.lineTo(p1->x()-(p1->width()/2),p1->y());
    }
    else
    {
        qreal left, bottom, right, y = p1->y(), lastx = p1->x() + (p1->width() / 2);
        patt.moveTo(lastx, y);
        pattest = QPainterPath();
        foreach(auto prox, proxys)
        {

            bool reWhider = true;

            left = prox->mapToScene(prox->boundingRect().left(), 0).x();
            right = prox->mapToScene(prox->boundingRect().right(), 0).x();
            bottom = prox->mapToScene(0, prox->boundingRect().bottom()).y();
            QPainterPath pathpart = QPainterPath();
            int tms = 0;
            int oldtms = 0;
            while (reWhider)
            {
                tms = 0;
                pathpart = QPainterPath();
                pathpart.moveTo(left - (oldtms + 1) * 20, y);
                pathpart.lineTo(left - (oldtms + 1) * 20, bottom + (oldtms + 1) * 20);
                pathpart.lineTo(right + (oldtms + 1) * 20, bottom + (oldtms + 1) * 20);
                pathpart.lineTo(right + (oldtms + 1) * 20, y);
                pattest.addRect(pathpart.boundingRect());
                pattest.addPath(pathpart);
                auto lst = scene()->items(pathpart.boundingRect(), Qt::IntersectsItemBoundingRect);
                reWhider = false;
                foreach(auto i, lst)
                {
                    PinLineColision* x = dynamic_cast<PinLineColision*>(i);
                    if (x)
                    {
                        if (x != this && x->collidesWithItem(prox, Qt::IntersectsItemBoundingRect))
                        {
                            tms += 1;
                        }
                    }
                }
                if (oldtms < tms)
                {
                    reWhider = true;
                    oldtms = tms;
                }

            }
            pathpart = QPainterPath();
            pathpart.moveTo(lastx, y);
            pathpart.lineTo(left - (oldtms + 1) * 15, y);
            pathpart.lineTo(left - (oldtms + 1) * 15, bottom + (oldtms + 1) * 15);
            pathpart.lineTo(right + (oldtms + 1) * 15, bottom + (oldtms + 1) * 15);
            pathpart.lineTo(right + (oldtms + 1) * 15, y);
            patt.addPath(pathpart);
            lastx = right + (oldtms + 1) * 15;
        }
        patt.lineTo(p1->Dot()->x(), p1->Dot()->y());
    }
}

PinLineColision::PinLineColision(Pin *p,QThread* thr)
{
    if (thr != nullptr)
    {
        moveToThread(thr);
    }
    this->p1=p;
    setZValue(3);
    this->Dot=p->Dot();

}

void PinLineColision::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    if (p1->chain == nullptr)
        painter->setPen(QPen(Qt::red, 5));
    else
        painter->setPen(QPen(p1->chain->color, 5));

    painter->drawPath(shape());
}
