#pragma once

#include <QGraphicsItem>
#include<qobject.h>
#include<qpainter.h>

class Dot  : public QGraphicsObject
{
	Q_OBJECT

public:
	Dot(QGraphicsObject* parent = nullptr);
	int type() const override;
	int x();
	int y();
	void x(int x);
	void y(int y);
	void EmitIs_inMove(bool moving)
	{
		emit Is_inMove(moving);
	}

	void Emit_Moving()
	{
		emit moving(this);
	}
	~Dot();
	void WhPl();
	void WhMin();
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
	QRectF boundingRect() const override;//
	QPainterPath shape() const override;//

signals:
	void Is_inMove(bool moving);
	void moving(Dot* d);
public slots:
	void VerticalDot(Dot* d);
	void HorizontalDot(Dot* d);
private:
	int Linecounter = 0;

};
