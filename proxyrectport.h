#include<qgraphicsitem.h>
#ifndef PROXYRECTPORT_H
#define PROXYRECTPORT_H

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
    qreal left() {return mapToScene(boundingRect().left(), 0).x(); }
    qreal right() { return mapToScene(boundingRect().right(), 0).x(); }
    qreal bottom() { return mapToScene(0, boundingRect().bottom()).y(); }
    qreal top() { return mapToScene(0, boundingRect().top()).y(); }
    QPointF center() { return mapToScene(boundingRect().center()); }
private:
    Port* port;
    QColor colo;
    QRectF rect;

};

#endif // PROXYRECTPORT_H
