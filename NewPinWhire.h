
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
#ifndef NEWPINWHIRE_H
#define NEWPINWHIRE_H
#include"CustomColliderLineRecoursive.h"
#include<qobject.h>
class Pin;
#include"Pin.h"
class NewPinWhire  : public CustomColliderLineRecoursive
{
	Q_OBJECT
public:
	NewPinWhire(Pin* p, QThread* th);
	~NewPinWhire();
};
#endif
