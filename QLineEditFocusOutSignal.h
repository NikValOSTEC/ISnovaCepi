
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
#ifndef QLINEEDITFOCUSOUTSIGNAL_H
#define QLINEEDITFOCUSOUTSIGNAL_H
#include <QLineEdit>

class QLineEditFocusOutSignal  : public QLineEdit
{
	Q_OBJECT

public:
	QLineEditFocusOutSignal(QWidget *parent);
	~QLineEditFocusOutSignal();
	virtual void focusInEvent(QFocusEvent* e);
	virtual void focusOutEvent(QFocusEvent* e);
signals:
	void focussed(bool hasFocus);
};
#endif