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
/// ������������ QGraphicsView
/// <para>
/// ����� ��� ���� ��� �� ������������ ����� � ��� ����� � EVENT FILTER
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
	/// ����������
	/// </summary>
	~GView();
	/// <summary>
	/// ����� � ������ �����������
	/// </summary>
	/// <returns></returns>
	MYGraphicsScene* GScene();
	/// <summary>
	/// ��������
	/// </summary>
	/// <param name="event"></param>
	void mouseMoveEvent(QMouseEvent* event) override;
	/// <summary>
	/// ��������
	/// </summary>
	/// <param name="event"></param>
	void mouseReleaseEvent(QMouseEvent* event) override;
	/// <summary>
	/// ��������
	/// </summary>
	/// <param name="event"></param>
	void mousePressEvent(QMouseEvent* event) override;
	/// <summary>
	/// ��������
	/// </summary>
	/// <param name="event"></param>
	void dropEvent(QDropEvent* event)override;
	/// <summary>
	/// ��������
	/// </summary>
	/// <param name="event"></param>
	void dragEnterEvent(QDragEnterEvent* event) override;
	/// <summary>
	/// ��������
	/// </summary>
	/// <param name="event"></param>
	void dragMoveEvent(QDragMoveEvent* event) override;
	/// <summary>
	/// ��������
	/// </summary>
	/// <param name="event"></param>
	int lastselected = 0;
};
#endif
