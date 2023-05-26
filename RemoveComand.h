
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
#ifndef REMOVECOMAND_H
#define REMOVECOMAND_H
class Port;
#include"port.h"

class RemovePortComand  : public QUndoCommand
{
public:
	RemovePortComand(Port* p);
	~RemovePortComand();	
	void undo() override;
	void redo() override;
	QString name;
	AddComand* addcom;
	View* v;
	int xx, yy;
};
#endif