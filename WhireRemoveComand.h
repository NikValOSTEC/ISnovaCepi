
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
#ifndef WHIREREMOVECOMAND_H
#define WHIREREMOVECOMAND_H
class AddWhireCommand;
#include"AddWhireCommand.h"
class NewWhire;
#include"NewWhire.h"
class AddPinComand;
#include"AddPinComand.h"
#include<QUndoCommand>
class WhireRemoveComand  : public QUndoCommand
{
public:
	WhireRemoveComand(NewWhire* w);
	~WhireRemoveComand();
	void undo() override;
	void redo() override;
	AddPinComand* p1, * p2;
	AddWhireCommand* wc;
};
#endif
