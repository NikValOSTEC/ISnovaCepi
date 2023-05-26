
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
#ifndef NEWWHIRE_H
#define NEWWHIRE_H
#pragma once
class Chain;
#include"chain.h"
class CustomColliderLineRecoursive;
#include"CustomColliderLineRecoursive.h"
class AddWhireCommand;
#include"AddWhireCommand.h"
class Pin;
#include"Pin.h"

class NewWhire  : public CustomColliderLineRecoursive
{
	Q_OBJECT
private:
public:

	Pin* p1 = nullptr, * p2 = nullptr;
	Chain* chain = nullptr;
	NewWhire(Pin*pp1,Pin*pp2,AddWhireCommand* comm);
	~NewWhire();
	AddWhireCommand* command;
};
#endif
