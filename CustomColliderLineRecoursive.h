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
/// ����� � ����������� ���������
/// </summary>
class CustomColliderLineRecoursive  : public QGraphicsObject
{
	Q_OBJECT
public:
	/// <summary>
	/// ���� �������� � ����� �� � ����� ��� ������� ������� � ����
	/// </summary>
	/// <returns></returns>
	virtual QColor color();
	/// <summary>
	/// ������ QGraphicsItem
	/// </summary>
	/// <param name="Vertical_f_Horiz_t">�������������� ��� ������������ ����� false - ������������ true - ��������������</param>
	/// <param name="d1">������� ����� 1</param>
	/// <param name="d2">������� ����� 2</param>
	/// <param name="parent">������������ ����� ����� ��� ��������� �������� ���������</param>
	CustomColliderLineRecoursive(bool Vertical_f_Horiz_t,Dot* d1,Dot* d2, CustomColliderLineRecoursive* parent=nullptr);
	/// <summary>
	/// ������� ����� � ��� �������� (������������� �����)
	/// </summary>
	~CustomColliderLineRecoursive();
	/// <summary>
	/// ����� ��� ����� ��������� ���� ���� �� �����
	/// <para> 
	/// ��. https://doc.qt.io/qt-6/qgraphicsitem.html
	/// </para>
	/// </summary>
	/// <returns>���� ����������� � ����������� ��� ����������� � ��������������</returns>
	QRectF boundingRect() const override;//
	/// <summary>
	/// ����� ��� ���������
	/// <para> 
	/// ��. https://doc.qt.io/qt-6/qgraphicsitem.html
	/// </para>
	/// </summary>
	/// <returns></returns>
	QPainterPath shape() const override;//
	/// <summary>
	/// ���������
	/// <para> 
	/// ��. https://doc.qt.io/qt-6/qgraphicsitem.html
	/// </para>
	/// </summary>
	/// <param name="painter"></param>
	/// <param name="option"></param>
	/// <param name="widget"></param>
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
	/// <summary>
	/// ��������� �� �������...
	/// </summary>
	/// <param name="fw"></param>
	void setFixWay(ColisionFixWay fw);
	/// <summary>
	/// ��� ���������� ������ ������ �������
	/// </summary>
	QVector<QGraphicsItem*>itsmine;
	/// <summary>
	/// �������������� ��� ������������ ����� false - ������������ true - ��������������
	/// </summary>
	bool Vertical_f_Horizontal_t;
	/// <summary>
	/// ����������� ����������� ��� �������� ���������� ����� ��������
	/// </summary>
	int JumpDerection = 1;
public slots:
	/// <summary>
	/// �������� ��������
	/// <param>
	/// 
	/// <param name="times">���� �� �� ���� � ������ ���� ��� ��������� ��������</param>
	void FixColliding(int times=0);
	/// <summary>
	/// ������� �������� ����� ( ������������ )
	/// </summary>
	void ClearInside();
	/// <summary>
	/// ����� ����������� ����� �� ���������
	/// </summary>
	void setVertical();
	/// <summary>
	/// ����� ����������� ����� �� �����������
	/// </summary>
	void setHorizontal();
	/// <summary>
	/// ���� �� ���������� ����� ��������
	/// </summary>
	/// <param name="itm"></param>
	void JumpFrom(QGraphicsItem* itm);
protected:
	/// <summary>
	/// ����� ����������� ������
	/// </summary>
	Dot* d1, *d2;
	/// <summary>
	/// �� �������
	/// </summary>
	ColisionFixWay fixway;
	/// <summary>
	///�������� �����
	/// </summary>
	QVector<QGraphicsObject*> inside;
	/// <summary>
	/// ��������� ���������� ������
	/// </summary>
	ProxyRectPort* lastcolide=nullptr;
	int lastleft, lastbottom;
	/// <summary>
	/// ������������ �����
	/// </summary>
	CustomColliderLineRecoursive* Parent;

};

#endif
