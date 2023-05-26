
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
#ifndef ADDCOMAND_H
#define ADDCOMAND_H
#include <QUndoCommand>
#include<QDebug>
class View;
#include"view.h"
class Port;
#include"port.h"

class AddComand  : public QUndoCommand
{
public:
	AddComand(View* v, int x, int y,QString name="");
	~AddComand();
	void undo() override;
	void redo() override;
	Port* p;
	int xx, yy;
	View* v;
	QString name;
};
#endif
