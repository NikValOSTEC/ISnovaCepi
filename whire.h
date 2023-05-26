#ifndef WHIRE_H
#define WHIRE_H

#include <QColorDialog>
#include<qcoreapplication.h>
#include<QGraphicsItem>
#include<QObject>
#include<QVector>
#include <QGraphicsItem>
#include <QObject>
class AddWhireCommand;
#include"AddWhireCommand.h"
class Chain;
#include"chain.h"
class Pin;
#include"Pin.h"

class Whire : public QGraphicsItem,QObject
{
private:
    QPainterPath patt;
public:
    AddWhireCommand* command;
    Whire(Pin* p1, Pin* p2, AddWhireCommand* comm);
    QRectF boundingRect() const override;//
    QPainterPath shape() const override;//
    void updateShape(bool colision = false);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    Pin* p1=nullptr, * p2=nullptr;
    ~Whire();
    void CollisionFix(bool fix=true);
    void move(bool left_rigth, int x);
    Chain* chain=nullptr;
    static void AddComandW(Pin* p1, Pin* p2);
};

#endif // WHIRE_H
