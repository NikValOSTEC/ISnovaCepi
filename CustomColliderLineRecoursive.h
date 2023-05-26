
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
#ifndef CUSTOMCOLLIDERLINERECOURSIVE_H
#define CUSTOMCOLLIDERLINERECOURSIVE_H
class ProxyRectPort;
#include"proxyrectport.h"
class Dot;
#include"Dot.h"
#include <QGraphicsObject>

enum ColisionFixWay
{
	none, run, flow
};

class CustomColliderLineRecoursive  : public QGraphicsObject
{
	Q_OBJECT
public:
	CustomColliderLineRecoursive(bool Vertical_f_Horiz_t,Dot* d1,Dot* d2, CustomColliderLineRecoursive* parent=nullptr);
	~CustomColliderLineRecoursive();
	QRectF boundingRect() const override;//
	QPainterPath shape() const override;//
	virtual void FixColliding();
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
	void setFixWay(ColisionFixWay fw);
	QVector<QGraphicsItem*>itsmine;
public slots:
	void SimpleShape(bool bl);
	void setVertical();
	void setHorizontal();
	void JumpFrom(QGraphicsItem* itm);
private:
	bool Vertical_f_Horizontal_t;
	Dot* d1, *d2;
	ColisionFixWay fixway;
	QVector<QGraphicsObject*> inside;
	ProxyRectPort* lastcolide=nullptr;
	int lastleft, lastbottom;
	CustomColliderLineRecoursive* Parent;

};

#endif
