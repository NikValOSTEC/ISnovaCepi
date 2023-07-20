#pragma once

#ifndef PROXYRECTPORT_H
#define PROXYRECTPORT_H
#include<qgraphicsitem.h>
#include<QPainter>
class Port;
/// <summary>
/// Прослойка для перемещения разъема по сцене
/// </summary>
class ProxyRectPort: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    /// <summary>
    /// Создает прослойку вкладывает в нее разъем
    /// </summary>
    /// <param name="port">Вложеный разъем</param>
    ProxyRectPort(Port*port);
    /// <summary>
    /// Сигна о перемещении
    /// </summary>
    void EmitMove();
    /// <summary>
    /// <para> 
    /// см. https://doc.qt.io/qt-6/qgraphicsitem.html
    /// </para>
    /// </summary>
    QPainterPath shape()const override;
    /// <summary>
    /// <para> 
    /// см. https://doc.qt.io/qt-6/qgraphicsitem.html
    /// </para>
    /// </summary>
    QRectF boundingRect() const override;
    /// <summary>
    /// <para> 
    /// см. https://doc.qt.io/qt-6/qgraphicsitem.html
    /// </para>
    /// </summary>
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    /// <summary>
    /// костыль аля bounding rect
    /// </summary>
    /// <returns></returns>
    QRectF geometry();
    /// <summary>
    /// установка костыл аля bounding rect
    /// </summary>
    /// <param name="rec"></param>
    void geometry(QRectF rec);
    /// <summary>
    /// Установка вложенного разъема
    /// </summary>
    /// <param name="port"></param>
    void setconnector(Port* port);
    /// <summary>
    /// Вложенный порт
    /// </summary>
    /// <returns></returns>
    Port *getport();
    /// <summary>
    /// Цвет прокси (Шапка над разъемом)
    /// </summary>
    /// <returns></returns>
    QColor color();
    /// <summary>
    /// установка цвета прокси (Шапка над разъемом)
    /// </summary>
    /// <returns></returns>
    void color(QColor c);
    /// <summary>
    /// удаление прокси и вложенного разъема
    /// </summary>
    ~ProxyRectPort();
    /// <summary>
    /// пересчет местоположения от колизий и обновление вложенного разъема
    /// </summary>
    /// <param name="upd"></param>
    /// <param name="i"></param>
    void Update(bool upd=false, int i=0);
    /// <summary>
    /// Нужен для обновления через GView
    /// </summary>
    /// <returns></returns>
    int type() const override;
    /// <summary>
    /// Проверка коллизий с проводами
    /// </summary>
    /// <param name="upd"></param>
    void ColiderCheck(bool upd=true);
    /// <summary>
    ///  Проверка коллизий разъемами (рекурия)
    /// </summary>
    /// <param name="xx">направление смещения в случае рекурсивного наложения</param>
    /// <param name="yy">направление смещения в случае рекурсивного наложения</param>
    void ProxyColider(int xx=0,int yy=0);
    /// <summary>
    /// координата по x;
    /// </summary>
    /// <returns></returns>
    qreal XX();
    /// <summary>
    /// координата по y;
    /// </summary>
    /// <returns></returns>
    qreal YY();    
    /// <summary>
    /// установка координаты по x;
    /// </summary>
    /// <returns></returns>
    void XX(qreal x);
    /// <summary>
    /// установка координаты по x;
    /// </summary>
    /// <returns></returns>
    void YY(qreal y);
    /// <summary>
    /// Левая сторона
    /// </summary>
    /// <returns>x левого края</returns>
    qreal left() {return mapToScene(boundingRect().left(), 0).x(); }
    /// <summary>
    /// Правая сторона
    /// </summary>
    /// <returns>x правого края</returns>
    qreal right() { return mapToScene(boundingRect().right(), 0).x(); }
    /// <summary>
    /// Низ
    /// </summary>
    /// <returns>y нижнего края</returns>
    qreal bottom() { return mapToScene(0, boundingRect().bottom()).y(); }
    /// <summary>
    /// Верх
    /// </summary>
    /// <returns>y верхнего края</returns>
    qreal top() { return mapToScene(0, boundingRect().top()).y(); }
    /// <summary>
    /// координаты центра
    /// </summary>
    /// <returns></returns>
    QPointF center() { return mapToScene(boundingRect().center()); }
signals:
        /// <summary>
        /// сигнал отметка начало перемещения
        /// </summary>
        void strartMove();
private:
    /// <summary>
    /// вложенный разъем
    /// </summary>
    Port* port;
    /// <summary>
    /// цвет прокси
    /// </summary>
    QColor colo;
    /// <summary>
    /// костыль над boundingrect
    /// </summary>
    QRectF rect;

};

#endif // PROXYRECTPORT_H
