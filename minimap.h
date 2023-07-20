#pragma once
#ifndef MINIMAP_H
#define MINIMAP_H
#include"qevent.h"
class View;
#include<qgraphicsview.h>
/// <summary>
/// ���� �����
/// <para> 
/// ������� �� �� ����� ��� � �������� �����������, �� � ������ �������
/// </para>
/// </summary>
class minimap  : public QGraphicsView
{
	Q_OBJECT

public:
	/// <summary>
	/// ������ ����� � v
	/// </summary>
	/// <param name="v">�������� �����������</param>
	minimap(View *v);
	/// <summary>
	/// ��������
	/// </summary>
	/// <param name="event"></param>
	void mouseMoveEvent(QMouseEvent* event)override; 
	/// <summary>
	/// ��������
	/// </summary>
	/// <param name="event"></param>
	void mouseReleaseEvent(QMouseEvent* event)override;
	/// <summary>
	/// ��������
	/// </summary>
	/// <param name="event"></param>
	void mousePressEvent(QMouseEvent* event)override;
	/// <summary>
	/// ��������
	/// </summary>
	/// <param name="event"></param>
	void mouseDoubleClickEvent(QMouseEvent* event) override;
#if QT_CONFIG(wheelevent)
	/// <summary>
	/// ��������
	/// </summary>
	/// <param name="event"></param>
	void wheelEvent(QWheelEvent* e);
#endif
	/// <summary>
	/// ����������
	/// </summary>
	~minimap();
	/// <summary>
	/// �������� �����������
	/// </summary>
	View* v;
	float sclX, sclY;
public slots:
	/// <summary>
	/// �������� �������
	/// </summary>
	void rescale();
};
#endif
