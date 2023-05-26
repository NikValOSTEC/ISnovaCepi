
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
#ifndef ADDPINCOMAND_H
#define ADDPINCOMAND_H
class Port;
#include"port.h"
class Pin;
#include"Pin.h"
class AddComand;
#include<QUndoCommand>
#include<QString>
#include"AddComand.h"

class AddPinComand  : public QUndoCommand
{
public:
	AddPinComand(Port*p,QString name="");
	~AddPinComand();
	void undo() override;
	void redo() override;
	QString name = "";
	Pin* pn = nullptr;
	AddComand* prt;
};
#endif
