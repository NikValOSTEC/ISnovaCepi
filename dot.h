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

class Dot  : public QGraphicsObject
{
	Q_OBJECT

public:
	Dot(QGraphicsObject* parent = nullptr);
	int type() const override;
	QColor cl;
	bool triangle;
	bool bg;
	int x();
	int y();
	void x(int x);
	void y(int y);
	void setColor(QColor cl);
	void setTriangle(bool bl);
	void setBig(bool bl);
	Pin* pn();
	CustomColliderLineRecoursive*Vdot, *Hdot;
	void EmitIs_inMove(bool moving)
	{
		emit Is_inMove(moving);
	}
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
	~Dot();
	QVector<NewWhire*>whires;
	void WhPl();
	void WhMin();
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
	QRectF boundingRect() const override;//
	QPainterPath shape() const override;//
	int whrscount()
	{
		return Linecounter;
	}

signals:
	void Is_inMove(bool moving);
	void moving(Dot* d);
public slots:
	void VerticalDot(Dot* d);
	void HorizontalDot(Dot* d);
private:
	int Linecounter = 0;
	Pin* _pin;

};
#endif
