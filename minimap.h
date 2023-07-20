#pragma once
#ifndef MINIMAP_H
#define MINIMAP_H
#include"qevent.h"
class View;
#include<qgraphicsview.h>
/// <summary>
/// Мини карта
/// <para> 
/// Выводит ту же сцену что и основное отображение, но в другом маштабе
/// </para>
/// </summary>
class minimap  : public QGraphicsView
{
	Q_OBJECT

public:
	/// <summary>
	/// крадем сцену у v
	/// </summary>
	/// <param name="v">Основное отображение</param>
	minimap(View *v);
	/// <summary>
	/// Перегруз
	/// </summary>
	/// <param name="event"></param>
	void mouseMoveEvent(QMouseEvent* event)override; 
	/// <summary>
	/// Перегруз
	/// </summary>
	/// <param name="event"></param>
	void mouseReleaseEvent(QMouseEvent* event)override;
	/// <summary>
	/// Перегруз
	/// </summary>
	/// <param name="event"></param>
	void mousePressEvent(QMouseEvent* event)override;
	/// <summary>
	/// Перегруз
	/// </summary>
	/// <param name="event"></param>
	void mouseDoubleClickEvent(QMouseEvent* event) override;
#if QT_CONFIG(wheelevent)
	/// <summary>
	/// Перегруз
	/// </summary>
	/// <param name="event"></param>
	void wheelEvent(QWheelEvent* e);
#endif
	/// <summary>
	/// Деструктор
	/// </summary>
	~minimap();
	/// <summary>
	/// Основное отображение
	/// </summary>
	View* v;
	float sclX, sclY;
public slots:
	/// <summary>
	/// Пересчет маштаба
	/// </summary>
	void rescale();
};
#endif
