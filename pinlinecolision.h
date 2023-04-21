#ifndef PINLINECOLISION_H
#define PINLINECOLISION_H

class Pin;
#include "pin.h"
#include <QGraphicsLineItem>

class PinLineColision : public QGraphicsLineItem,QObject
{
private:
    QPainterPath patt,pattest;
    dot* Dot;
public:
    Pin* p1;
    QRectF boundingRect() const override;//
    QPainterPath shape() const override;//
    void updateShape();
    void FixColliding();

    qreal y();
    PinLineColision(Pin* p,QThread* thr=nullptr);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
};

#endif // PINLINECOLISION_H
