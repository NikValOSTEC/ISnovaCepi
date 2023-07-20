#pragma once
#ifndef DOT_H
#define DOT_H
#include<QtMath>
#include<QWidget>
#include<QStyleOptionGraphicsItem>
#include<QGraphicsObject>
#include<QPainter>
class CustomColliderLineRecoursive;
class NewWhire;
class Pin;
#include"pin.h"

/// <summary>
/// ����� ����� ������������� �����
/// </summary>
class Dot  : public QGraphicsObject
{
	Q_OBJECT

public:
	/// <summary>
	/// QGraphicsItem
	/// <para> 
	/// ��. https://doc.qt.io/qt-6/qgraphicsitem.html
	/// </para>
	/// </summary>
	/// <param name="parent"></param>
	Dot(QGraphicsObject* parent = nullptr);
	/// <summary>
	/// ��� ������ ����� GView
	/// </summary>
	/// <returns></returns>
	int type() const override;
	/// <summary>
	/// ���� �����
	/// </summary>
	QColor cl;
	/// <summary>
	/// ����������� �� �����
	/// </summary>
	bool triangle;
	/// <summary>
	/// ������� �� �����
	/// </summary>
	bool bg;
	/// <summary>
	/// </summary>
	/// <returns>���������� x</returns>
	int x();
	/// <summary>
	/// </summary>
	/// <returns>���������� y</returns>
	int y();
	/// <summary>
	/// ������������� ���������� �� ��� x
	/// </summary>
	void x(int x);
	/// <summary>
	/// ������������� ���������� �� ��� y
	/// </summary>
	void y(int y);
	/// <summary>
	/// ������������� ����
	/// </summary>
	/// <param name="cl">����</param>
	void setColor(QColor cl);
	/// <summary>
	/// ������ ����������� ��� �������
	/// </summary>
	/// <param name="bl"></param>
	void setTriangle(bool bl);
	/// <summary>
	/// ������ ������� ��� ���������
	/// </summary>
	/// <param name="bl"></param>
	void setBig(bool bl);
	/// <summary>
	/// ������� �� ������� ������ ����� �������� �����������
	/// </summary>
	Pin* pn();
	/// <summary>
	/// ����� ������������ ������ �����
	/// </summary>
	CustomColliderLineRecoursive*Vdot, *Hdot;
	void EmitIs_inMove(bool moving)
	{
		if (_pin != nullptr)
		{
			_pin->Update(false);
		}
		emit Is_inMove(moving);
	}
	/// <summary>
	/// ����������� �� ���������
	/// </summary>
	/// <param name="p"></param>
	void setPin(Pin* p);
	void Emit_Moving()
	{
		int x = pos().x();
		int y = pos().y();
		int mx, my;
		mx = x % 25;
		if (mx < 0)
			mx += 25;
		my = y % 25;
		if (my < 0)
			my += 25;
		if (mx > 12)
			x = x - mx + 25;
		else
			x = x - mx;
		if (y % 25 > 12)
			y = y - my + 25;
		else
			y = y - my;
		setPos(x, y);
		emit moving(this);
	}
	/// <summary>
	/// ����������
	/// </summary>
	~Dot();
	/// <summary>
	/// ������� ������������ ������ �����
	/// </summary>
	QVector<NewWhire*>whires;
	/// <summary>
	/// ������� �������� ����� �� 0 ��������
	/// </summary>
	void WhPl();
	void WhMin();
	/// <summary>
	/// <para> 
	/// ��. https://doc.qt.io/qt-6/qgraphicsitem.html
	/// </para>
	/// </summary>
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
	/// <summary>
	/// <para> 
	/// ��. https://doc.qt.io/qt-6/qgraphicsitem.html
	/// </para>
	/// </summary>
	QRectF boundingRect() const override;//
	/// <summary>
	/// <para> 
	/// ��. https://doc.qt.io/qt-6/qgraphicsitem.html
	/// </para>
	/// </summary>
	QPainterPath shape() const override;//
	int whrscount()
	{
		return Linecounter;
	}

signals:
	/// <summary>
	/// ������ � �������� �����
	/// </summary>
	void Is_inMove(bool moving);
	/// <summary>
	/// ������ � ����������� �����
	/// </summary>
	void moving(Dot* d);
public slots:
	/// <summary>
	/// ���� �� ��������� �������� ������ ��������� �����
	/// </summary>
	void VerticalDot(Dot* d);
	/// <summary>
	/// ���� �� ��������� �������� ������ ��������� �����
	/// </summary>
	void HorizontalDot(Dot* d);
private:
	/// <summary>
	/// ������� �����
	/// </summary>
	int Linecounter = 0;
	/// <summary>
	/// ������� �� ������� ������ ����� �������� �����������
	/// </summary>
	Pin* _pin;

};
#endif
