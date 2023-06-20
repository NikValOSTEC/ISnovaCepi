#pragma once
#ifndef CUSTOMCOLLIDERLINERECOURSIVE_H
#define CUSTOMCOLLIDERLINERECOURSIVE_H

#include<qobject.h>
#include<qgraphicsobject>
#include"qgraphicsscene.h"
class Dot;
class ProxyRectPort;

enum ColisionFixWay
{
	none, run, flow
};

class CustomColliderLineRecoursive  : public QGraphicsObject
{
	Q_OBJECT
public:
	CustomColliderLineRecoursive(bool Vertical_f_Horiz_t,Dot* d1,Dot* d2, CustomColliderLineRecoursive* parent=nullptr);
	~CustomColliderLineRecoursive();
	QRectF boundingRect() const override;//
	QPainterPath shape() const override;//
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
	void setFixWay(ColisionFixWay fw);
	QVector<QGraphicsItem*>itsmine;
	bool Vertical_f_Horizontal_t;
public slots:
	void FixColliding();
	void ClearInside();
	void setVertical();
	void setHorizontal();
	void JumpFrom(QGraphicsItem* itm);
protected:
	Dot* d1, *d2;
	ColisionFixWay fixway;
	QVector<QGraphicsObject*> inside;
	ProxyRectPort* lastcolide=nullptr;
	int lastleft, lastbottom;
	CustomColliderLineRecoursive* Parent;
	int r, g, b;

};

#endif
