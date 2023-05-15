#ifndef DOT_H
#define DOT_H
#include<QGraphicsItem>
#include <QObject>
#include<QList>
class Pin;
#include"pin.h"
class Whire;
#include "whire.h"
class dotold : public QGraphicsItem,QObject
{
public:
    ~dotold();
    dotold(Pin* p,QThread* thr=nullptr);
    QColor color;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    QRectF boundingRect() const override;//
    QPainterPath shape() const override;//
    qreal x();
    void x(int x);
    qreal y();
    void y(int y);
    void Uupdate(bool collision=false, QVector<dotold*>* nnot=new QVector<dotold*>());
    void AddWhire(Whire* w);
    void RemoveWhire(Whire*w);
    void AddDot(dotold* w);
    void RemoveDot(dotold*w);
    int type() const override;
    QVector<Whire*>whires;
private:
    QVector<dotold*>verticalMove;
    bool Big=false;
    Pin* pin;
    Whire* whire;
};

#endif // DOT_H
