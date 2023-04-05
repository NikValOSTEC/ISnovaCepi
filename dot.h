#ifndef DOT_H
#define DOT_H
#include<QGraphicsItem>
#include <QObject>
#include<QList>
class Pin;
#include"pin.h"
class Whire;
#include "whire.h"
class dot : public QGraphicsItem
{
public:
    ~dot();
    dot(Pin* p);
    QColor color;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    QRectF boundingRect() const override;//
    QPainterPath shape() const override;//
    qreal x();
    void x(int x);
    qreal y();
    void y(int y);
    void Uupdate(bool collision=false, QVector<dot*>* nnot=new QVector<dot*>());
    void AddWhire(Whire* w);
    void RemoveWhire(Whire*w);
    void AddDot(dot* w);
    void RemoveDot(dot*w);
    int type() const override;
    QVector<Whire*>whires;
private:
    QVector<dot*>verticalMove;
    bool Big=false;
    Pin* pin;
    Whire* whire;
};

#endif // DOT_H
