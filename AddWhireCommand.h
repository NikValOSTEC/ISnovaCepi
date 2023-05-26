
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
#ifndef ADDWHIRECOMMAND_H
#define ADDWHIRECOMAND_H
#include<QUndoCommand>
class AddPinComand;
#include"AddPinComand.h"
class NewWhire;
#include"NewWhire.h"
class AddWhireCommand: public QUndoCommand
{
public:
	AddWhireCommand(AddPinComand* p11, AddPinComand* p22);
	~AddWhireCommand();
	void undo() override;
	void redo() override;
	AddPinComand* p1, *p2;
	NewWhire* whire;
};
#endif
