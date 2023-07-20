#pragma once
#ifndef GITEMFRAME_H
#define GITEMFRAME_H
#include<QPen>
#include<QPainter>
#include<qgraphicsitem.h>
/// <summary>
/// Красная рамка
/// </summary>
class GItemFrame  : public  QGraphicsItem
{

public:
	/// <summary>
	/// QGraphicsItem
	/// </summary>
	GItemFrame();
	/// <summary>
	/// Деструктор
	/// </summary>
	~GItemFrame();
	/// <summary>
	/// <para> 
	/// см. https://doc.qt.io/qt-6/qgraphicsitem.html
	/// </para>
	/// </summary>
	QRectF boundingRect() const override;//
	/// <summary>
	/// <para> 
	/// см. https://doc.qt.io/qt-6/qgraphicsitem.html
	/// </para>
	/// </summary>
	QPainterPath shape() const override;//
	/// <summary>
	/// <para> 
	/// см. https://doc.qt.io/qt-6/qgraphicsitem.html
	/// </para>
	/// </summary>
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;


};
#endif
