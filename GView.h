#pragma once

#include <QGraphicsView>
#include "mygraphicsscene.h"

class GView  : public QGraphicsView
{

public:
	GView(QObject *parent);
	~GView();

	MYGraphicsScene* GScene();
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	int lastselected = 0;
};
