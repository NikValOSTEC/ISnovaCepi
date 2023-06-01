#pragma once
#ifndef GVIEW_H
#define GVIEW_H
#include<qobject.h>
class MYGraphicsScene;
#include"qgraphicsview.h"
#include<qdrag.h>
#include<qevent.h>
#include<QMimeData>

class GView  : public QGraphicsView
{

public:
	GView(QObject *parent);
	~GView();

	MYGraphicsScene* GScene();
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
	void dropEvent(QDropEvent* event)override;
	void dragEnterEvent(QDragEnterEvent* event) override;
	void dragMoveEvent(QDragMoveEvent* event) override;
	int lastselected = 0;
};
#endif
