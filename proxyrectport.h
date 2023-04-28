#ifndef PROXYRECTPORT_H
#define PROXYRECTPORT_H
#include<QGraphicsSceneEvent>
#include <QGraphicsItem>
#include<qgraphicsscene.h>
#include <QObject>
#include <QWidget>
#include <QPainter>
#include<QColor>
class Port;
#include "port.h"

class ProxyRectPort:public QGraphicsItem
{
public:
    ProxyRectPort(Port*port);
    QPainterPath shape()const override;
    QRectF boundingRect() const override;
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF geometry();
    void geometry(QRectF rec);
    void setconnector(Port* port);
    Port *getport();
    QColor color();
    void color(QColor c);
    ~ProxyRectPort();
    void Update(bool upd=false);
    int type() const override;
    void ColiderCheck(bool upd=true);
    qreal XX();
    qreal YY();    
    void XX(qreal x);
    void YY(qreal y);
private:
    Port* port;
    QColor colo;
    QRectF rect;

};

#endif // PROXYRECTPORT_H
