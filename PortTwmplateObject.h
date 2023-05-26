
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
#ifndef PORTTWMPLATEOBJECT_H
#define PORTTWMPLATEOBJECT_H
#include<qobject.h>
#include<qwidget.h>
class PortTemplate;
#include"PortTemplate.h"
#include<qpushbutton.h>
class QLineEditFocusOutSignal;
#include"qlineedit.h"


class PortTwmplateObject  : public QWidget
{
	Q_OBJECT

public:
	PortTemplate* templ;
	QPushButton* editpb;
	QPushButton* delpb;
	QLineEditFocusOutSignal* name;
	void dragEnterEvent(QDragEnterEvent* event) override;
	void dropEvent(QDropEvent* event) override;
	void dragMoveEvent(QDragMoveEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;

public slots:
	void editPush();
	void delPush();
	void namecheck(bool foc);
public:
	PortTwmplateObject();
	~PortTwmplateObject();

};
#endif
