#pragma once

class NewWhire;
#include"NewWhire.h"


class Dot  : public QGraphicsObject
{
	Q_OBJECT

public:
	Dot(QGraphicsObject* parent = nullptr);
	int type() const override;
	QColor cl;
	int x();
	int y();
	void x(int x);
	void y(int y);
	CustomColliderLineRecoursive*Vdot, *Hdot;
	void EmitIs_inMove(bool moving)
	{
		emit Is_inMove(moving);
	}

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

};
