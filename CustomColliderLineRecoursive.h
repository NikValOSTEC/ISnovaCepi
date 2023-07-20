#pragma once
#ifndef CUSTOMCOLLIDERLINERECOURSIVE_H
#define CUSTOMCOLLIDERLINERECOURSIVE_H

#include<qobject.h>
#include<qgraphicsobject>
#include"qgraphicsscene.h"
class Dot;
class ProxyRectPort;

enum ColisionFixWay
{
	none, run, flow
};
/// <summary>
/// Линия с колизионной корекцией
/// </summary>
class CustomColliderLineRecoursive  : public QGraphicsObject
{
	Q_OBJECT
public:
	/// <summary>
	/// Цвет хранится в цепях не у линий нет прямого доступа в цепь
	/// </summary>
	/// <returns></returns>
	virtual QColor color();
	/// <summary>
	/// Просто QGraphicsItem
	/// </summary>
	/// <param name="Vertical_f_Horiz_t">Горизонтальная или вертикальная линия false - Вертикальная true - горизонтальная</param>
	/// <param name="d1">крайняя точка 1</param>
	/// <param name="d2">крайняя точка 2</param>
	/// <param name="parent">Родительская линия НУЖНА ДЛЯ КОРРЕКЦИИ КОЛЛИЗИИ РЕКУРСИЕЙ</param>
	CustomColliderLineRecoursive(bool Vertical_f_Horiz_t,Dot* d1,Dot* d2, CustomColliderLineRecoursive* parent=nullptr);
	/// <summary>
	/// Удаляет линию и все дочерние (коррекционные линии)
	/// </summary>
	~CustomColliderLineRecoursive();
	/// <summary>
	/// Линия без учета коррекции даже если не видна
	/// <para> 
	/// см. https://doc.qt.io/qt-6/qgraphicsitem.html
	/// </para>
	/// </summary>
	/// <returns>Зона необходимая к пересечению для отображения и взаимодействия</returns>
	QRectF boundingRect() const override;//
	/// <summary>
	/// Форма для отрисовки
	/// <para> 
	/// см. https://doc.qt.io/qt-6/qgraphicsitem.html
	/// </para>
	/// </summary>
	/// <returns></returns>
	QPainterPath shape() const override;//
	/// <summary>
	/// Отрисовка
	/// <para> 
	/// см. https://doc.qt.io/qt-6/qgraphicsitem.html
	/// </para>
	/// </summary>
	/// <param name="painter"></param>
	/// <param name="option"></param>
	/// <param name="widget"></param>
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
	/// <summary>
	/// Наработка на будущее...
	/// </summary>
	/// <param name="fw"></param>
	void setFixWay(ColisionFixWay fw);
	/// <summary>
	/// Уже обойденные данной линией объекты
	/// </summary>
	QVector<QGraphicsItem*>itsmine;
	/// <summary>
	/// Горизонтальная или вертикальная линия false - Вертикальная true - горизонтальная
	/// </summary>
	bool Vertical_f_Horizontal_t;
	/// <summary>
	/// Направление отступления при движении обойденных ранее объектов
	/// </summary>
	int JumpDerection = 1;
public slots:
	/// <summary>
	/// Пересчет коллизии
	/// <param>
	/// 
	/// <param name="times">чЧто бы не уйти в вечный цикл при неудачной коллизии</param>
	void FixColliding(int times=0);
	/// <summary>
	/// Очистка дочерних линий ( выравнивание )
	/// </summary>
	void ClearInside();
	/// <summary>
	/// Смена направления линии на вертикаль
	/// </summary>
	void setVertical();
	/// <summary>
	/// Смена направления линии на горизонталь
	/// </summary>
	void setHorizontal();
	/// <summary>
	/// уход от обойденных ранее объектов
	/// </summary>
	/// <param name="itm"></param>
	void JumpFrom(QGraphicsItem* itm);
protected:
	/// <summary>
	/// Точки соеденяемые линией
	/// </summary>
	Dot* d1, *d2;
	/// <summary>
	/// На будущее
	/// </summary>
	ColisionFixWay fixway;
	/// <summary>
	///Дочерние линии
	/// </summary>
	QVector<QGraphicsObject*> inside;
	/// <summary>
	/// последний обойденный разъем
	/// </summary>
	ProxyRectPort* lastcolide=nullptr;
	int lastleft, lastbottom;
	/// <summary>
	/// родительская линия
	/// </summary>
	CustomColliderLineRecoursive* Parent;

};

#endif
