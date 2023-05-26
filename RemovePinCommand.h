
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
#ifndef REMOVEPINCOMMAND_H
#define REMOVEPINCOMMAND_H
class Port;
class AddPinComand;
#include"port.h"
#include"AddPinComand.h"
class RemovePinCommand  : public QUndoCommand
{

public:
	RemovePinCommand(Pin*p);
	~RemovePinCommand();
	void undo() override;
	void redo() override;
	int pos = 0;
	QString name = "";
	AddPinComand* pinc;
	Port* prt;
	Pin* pin;

};
#endif
