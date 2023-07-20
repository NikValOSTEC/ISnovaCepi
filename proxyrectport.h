#pragma once

#ifndef PROXYRECTPORT_H
#define PROXYRECTPORT_H
#include<qgraphicsitem.h>
#include<QPainter>
class Port;
/// <summary>
/// ��������� ��� ����������� ������� �� �����
/// </summary>
class ProxyRectPort: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    /// <summary>
    /// ������� ��������� ���������� � ��� ������
    /// </summary>
    /// <param name="port">�������� ������</param>
    ProxyRectPort(Port*port);
    /// <summary>
    /// ����� � �����������
    /// </summary>
    void EmitMove();
    /// <summary>
    /// <para> 
    /// ��. https://doc.qt.io/qt-6/qgraphicsitem.html
    /// </para>
    /// </summary>
    QPainterPath shape()const override;
    /// <summary>
    /// <para> 
    /// ��. https://doc.qt.io/qt-6/qgraphicsitem.html
    /// </para>
    /// </summary>
    QRectF boundingRect() const override;
    /// <summary>
    /// <para> 
    /// ��. https://doc.qt.io/qt-6/qgraphicsitem.html
    /// </para>
    /// </summary>
    void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    /// <summary>
    /// ������� ��� bounding rect
    /// </summary>
    /// <returns></returns>
    QRectF geometry();
    /// <summary>
    /// ��������� ������ ��� bounding rect
    /// </summary>
    /// <param name="rec"></param>
    void geometry(QRectF rec);
    /// <summary>
    /// ��������� ���������� �������
    /// </summary>
    /// <param name="port"></param>
    void setconnector(Port* port);
    /// <summary>
    /// ��������� ����
    /// </summary>
    /// <returns></returns>
    Port *getport();
    /// <summary>
    /// ���� ������ (����� ��� ��������)
    /// </summary>
    /// <returns></returns>
    QColor color();
    /// <summary>
    /// ��������� ����� ������ (����� ��� ��������)
    /// </summary>
    /// <returns></returns>
    void color(QColor c);
    /// <summary>
    /// �������� ������ � ���������� �������
    /// </summary>
    ~ProxyRectPort();
    /// <summary>
    /// �������� �������������� �� ������� � ���������� ���������� �������
    /// </summary>
    /// <param name="upd"></param>
    /// <param name="i"></param>
    void Update(bool upd=false, int i=0);
    /// <summary>
    /// ����� ��� ���������� ����� GView
    /// </summary>
    /// <returns></returns>
    int type() const override;
    /// <summary>
    /// �������� �������� � ���������
    /// </summary>
    /// <param name="upd"></param>
    void ColiderCheck(bool upd=true);
    /// <summary>
    ///  �������� �������� ��������� (�������)
    /// </summary>
    /// <param name="xx">����������� �������� � ������ ������������ ���������</param>
    /// <param name="yy">����������� �������� � ������ ������������ ���������</param>
    void ProxyColider(int xx=0,int yy=0);
    /// <summary>
    /// ���������� �� x;
    /// </summary>
    /// <returns></returns>
    qreal XX();
    /// <summary>
    /// ���������� �� y;
    /// </summary>
    /// <returns></returns>
    qreal YY();    
    /// <summary>
    /// ��������� ���������� �� x;
    /// </summary>
    /// <returns></returns>
    void XX(qreal x);
    /// <summary>
    /// ��������� ���������� �� x;
    /// </summary>
    /// <returns></returns>
    void YY(qreal y);
    /// <summary>
    /// ����� �������
    /// </summary>
    /// <returns>x ������ ����</returns>
    qreal left() {return mapToScene(boundingRect().left(), 0).x(); }
    /// <summary>
    /// ������ �������
    /// </summary>
    /// <returns>x ������� ����</returns>
    qreal right() { return mapToScene(boundingRect().right(), 0).x(); }
    /// <summary>
    /// ���
    /// </summary>
    /// <returns>y ������� ����</returns>
    qreal bottom() { return mapToScene(0, boundingRect().bottom()).y(); }
    /// <summary>
    /// ����
    /// </summary>
    /// <returns>y �������� ����</returns>
    qreal top() { return mapToScene(0, boundingRect().top()).y(); }
    /// <summary>
    /// ���������� ������
    /// </summary>
    /// <returns></returns>
    QPointF center() { return mapToScene(boundingRect().center()); }
signals:
        /// <summary>
        /// ������ ������� ������ �����������
        /// </summary>
        void strartMove();
private:
    /// <summary>
    /// ��������� ������
    /// </summary>
    Port* port;
    /// <summary>
    /// ���� ������
    /// </summary>
    QColor colo;
    /// <summary>
    /// ������� ��� boundingrect
    /// </summary>
    QRectF rect;

};

#endif // PROXYRECTPORT_H
