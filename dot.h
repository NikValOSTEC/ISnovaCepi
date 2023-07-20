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
/// Класс Точки дляпостроения линий
/// </summary>
class Dot  : public QGraphicsObject
{
	Q_OBJECT

public:
	/// <summary>
	/// QGraphicsItem
	/// <para> 
	/// см. https://doc.qt.io/qt-6/qgraphicsitem.html
	/// </para>
	/// </summary>
	/// <param name="parent"></param>
	Dot(QGraphicsObject* parent = nullptr);
	/// <summary>
	/// для работы через GView
	/// </summary>
	/// <returns></returns>
	int type() const override;
	/// <summary>
	/// Цвет Линии
	/// </summary>
	QColor cl;
	/// <summary>
	/// треугольная ли точка
	/// </summary>
	bool triangle;
	/// <summary>
	/// Большая ли точка
	/// </summary>
	bool bg;
	/// <summary>
	/// </summary>
	/// <returns>Координату x</returns>
	int x();
	/// <summary>
	/// </summary>
	/// <returns>Координату y</returns>
	int y();
	/// <summary>
	/// Устанавливает координату по оси x
	/// </summary>
	void x(int x);
	/// <summary>
	/// Устанавливает координату по оси y
	/// </summary>
	void y(int y);
	/// <summary>
	/// Устанавливает Цвет
	/// </summary>
	/// <param name="cl">цвет</param>
	void setColor(QColor cl);
	/// <summary>
	/// Делает треугольной или круглой
	/// </summary>
	/// <param name="bl"></param>
	void setTriangle(bool bl);
	/// <summary>
	/// Делает большой или маленькой
	/// </summary>
	/// <param name="bl"></param>
	void setBig(bool bl);
	/// <summary>
	/// Контакт за которым данная точка ВОЗМОЖНО закрепленна
	/// </summary>
	Pin* pn();
	/// <summary>
	/// Линии использующие данную точку
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
	/// Закрепление за контактом
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
	/// Деструктор
	/// </summary>
	~Dot();
	/// <summary>
	/// провода использующие данную точку
	/// </summary>
	QVector<NewWhire*>whires;
	/// <summary>
	/// Счетчик проводов когда их 0 удаление
	/// </summary>
	void WhPl();
	void WhMin();
	/// <summary>
	/// <para> 
	/// см. https://doc.qt.io/qt-6/qgraphicsitem.html
	/// </para>
	/// </summary>
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
	/// <summary>
	/// <para> 
	/// см. https://doc.qt.io/qt-6/qgraphicsitem.html
	/// </para>
	/// </summary>
	QRectF boundingRect() const override;//
	/// <summary>
	/// <para> 
	/// см. https://doc.qt.io/qt-6/qgraphicsitem.html
	/// </para>
	/// </summary>
	QPainterPath shape() const override;//
	int whrscount()
	{
		return Linecounter;
	}

signals:
	/// <summary>
	/// Сигнал о смещении точки
	/// </summary>
	void Is_inMove(bool moving);
	/// <summary>
	/// Сигнал о перемещении точки
	/// </summary>
	void moving(Dot* d);
public slots:
	/// <summary>
	/// Слот на обработку смещения другой связанной точки
	/// </summary>
	void VerticalDot(Dot* d);
	/// <summary>
	/// Слот на обработку смещения другой связанной точки
	/// </summary>
	void HorizontalDot(Dot* d);
private:
	/// <summary>
	/// счетчик линий
	/// </summary>
	int Linecounter = 0;
	/// <summary>
	/// Контакт за которым данная точка ВОЗМОЖНО закрепленна
	/// </summary>
	Pin* _pin;

};
#endif
