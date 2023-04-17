#pragma once

#include <QGraphicsView>
#include<qgraphicsitem.h>
#include"mygraphicsscene.h"

class minimap  : public QGraphicsView
{
	Q_OBJECT

public:
	minimap(View *v);
	void mouseMoveEvent(QMouseEvent* event)override;
	void mouseReleaseEvent(QMouseEvent* event)override;
	void mousePressEvent(QMouseEvent* event)override;

	~minimap();
	View* v;
	float sclX, sclY;
public slots:
	void rescale();
};
