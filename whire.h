#ifndef WHIRE_H
#define WHIRE_H

#include <QGraphicsItem>
#include <QObject>
class Chain;
#include"chain.h"
class Pin;
#include"pin.h"

class Whire : public QGraphicsItem
{
private:
    QPainterPath patt;
public:
    Whire(Pin* p1, Pin* p2);
    QRectF boundingRect() const override;//
    QPainterPath shape() const override;//
    void updateShape(bool colision = false);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    Pin* p1, * p2;
    ~Whire();
    void CollisionFix(bool fix=true);
    void move(bool left_rigth, int x);
    Chain* chain;
};

#endif // WHIRE_H
