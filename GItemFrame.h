#pragma once
#include<QPainterPath>
#include <QGraphicsItem>
#include "qgraphicsproxywidget.h"
#include "qgraphicsscene.h"
#include "qpainter.h"
#include<qobject.h>

class GItemFrame  : public  QGraphicsItem
{

public:
	GItemFrame();
	~GItemFrame();
	QRectF boundingRect() const override;//
	QPainterPath shape() const override;//
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

};
