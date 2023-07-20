#pragma once
#ifndef GVIEW_H
#define GVIEW_H
#include<qobject.h>
class MYGraphicsScene;
#include"qgraphicsview.h"
#include<qdrag.h>
#include<qevent.h>
#include<QMimeData>
/// <summary>
/// Наследование QGraphicsView
/// <para>
/// Нужно для того что бы обрабатывать клики в том числе с EVENT FILTER
/// </para>
/// </summary>
class GView  : public QGraphicsView
{

public:
	/// <summary>
	/// QGraphicsView
	/// </summary>
	/// <param name="parent"></param>
	GView(QObject *parent);
	/// <summary>
	/// Деструктор
	/// </summary>
	~GView();
	/// <summary>
	/// Сцена в данном отображении
	/// </summary>
	/// <returns></returns>
	MYGraphicsScene* GScene();
	/// <summary>
	/// Перегруз
	/// </summary>
	/// <param name="event"></param>
	void mouseMoveEvent(QMouseEvent* event) override;
	/// <summary>
	/// Перегруз
	/// </summary>
	/// <param name="event"></param>
	void mouseReleaseEvent(QMouseEvent* event) override;
	/// <summary>
	/// Перегруз
	/// </summary>
	/// <param name="event"></param>
	void mousePressEvent(QMouseEvent* event) override;
	/// <summary>
	/// Перегруз
	/// </summary>
	/// <param name="event"></param>
	void dropEvent(QDropEvent* event)override;
	/// <summary>
	/// Перегруз
	/// </summary>
	/// <param name="event"></param>
	void dragEnterEvent(QDragEnterEvent* event) override;
	/// <summary>
	/// Перегруз
	/// </summary>
	/// <param name="event"></param>
	void dragMoveEvent(QDragMoveEvent* event) override;
	/// <summary>
	/// Перегруз
	/// </summary>
	/// <param name="event"></param>
	int lastselected = 0;
};
#endif
