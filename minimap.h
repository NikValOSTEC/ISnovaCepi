#pragma once
#ifndef MINIMAP_H
#define MINIMAP_H
#include"qevent.h"
class View;
#include<qgraphicsview.h>
class minimap  : public QGraphicsView
{
	Q_OBJECT

public:
	minimap(View *v);
	void mouseMoveEvent(QMouseEvent* event)override;
	void mouseReleaseEvent(QMouseEvent* event)override;
	void mousePressEvent(QMouseEvent* event)override;
	void mouseDoubleClickEvent(QMouseEvent* event) override;
#if QT_CONFIG(wheelevent)
	void wheelEvent(QWheelEvent* e);
#endif

	~minimap();
	View* v;
	float sclX, sclY;
public slots:
	void rescale();
};
#endif
