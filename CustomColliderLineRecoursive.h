#pragma once

#include <QGraphicsLineItem>
#include "dotold.h"
#include "Dot.h"
#include<qobject.h>

enum ColisionFixWay
{
	none, run, flow
};

class CustomColliderLineRecoursive  : public QGraphicsObject
{
	Q_OBJECT
public:
	CustomColliderLineRecoursive(bool Vertical_f_Horiz_t,Dot* d1,Dot* d2, QGraphicsObject* parent=nullptr);
	~CustomColliderLineRecoursive();
	QRectF boundingRect() const override;//
	QPainterPath shape() const override;//
	virtual void FixColliding();
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
	void setFixWay(ColisionFixWay fw);
public slots:
	void SimpleShape(bool bl);
	void setVertical();
	void setHorizontal();
private:
	bool Vertical_f_Horizontal_t;
	Dot* d1, *d2;
	ColisionFixWay fixway;
	QVector<QGraphicsObject*> inside;
};

