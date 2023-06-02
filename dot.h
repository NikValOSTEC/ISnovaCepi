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
