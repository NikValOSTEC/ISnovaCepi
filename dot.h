
class AddComand;
class AddPinComand;
class AddWhireCommand;
class Chain;
class ChainTable;
class CustomColliderLineRecoursive;
class Dot;
class GItemFrame;
class GView;
class MainWindow;
class minimap;
class MYGraphicsScene;
class NewPinWhire;
class NewWhire;
class Pin;
class PinTemplate;
class Port;
class PortLib;
class PortTemplate;
class PortTwmplateObject;
class ProxyRectPort;
class QLineEditFocusOutSignal;
class RemovePortComand;
class RemovePinCommand;
class RemovePortComand;
class SaveTemplates;
class View;
class WhireRemoveComand; 
#pragma once
#ifndef DOT_H
#define DOT_H
#include<QtMath>
#include<QWidget>
#include<QStyleOptionGraphicsItem>
#include<QGraphicsObject>
#include<QPainter>
class CustomColliderLineRecoursive;
#include"CustomColliderLineRecoursive.h"
class NewWhire;
#include"NewWhire.h"


class Dot  : public QGraphicsObject
{
	Q_OBJECT

public:
	Dot(QGraphicsObject* parent = nullptr);
	int type() const override;
	QColor cl;
	int x();
	int y();
	void x(int x);
	void y(int y);
	CustomColliderLineRecoursive*Vdot, *Hdot;
	void EmitIs_inMove(bool moving)
	{
		emit Is_inMove(moving);
	}

	void Emit_Moving()
	{
		emit moving(this);
	}
	~Dot();
	QVector<NewWhire*>whires;
	void WhPl();
	void WhMin();
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
	QRectF boundingRect() const override;//
	QPainterPath shape() const override;//
	int whrscount()
	{
		return Linecounter;
	}

signals:
	void Is_inMove(bool moving);
	void moving(Dot* d);
public slots:
	void VerticalDot(Dot* d);
	void HorizontalDot(Dot* d);
private:
	int Linecounter = 0;

};
#endif
