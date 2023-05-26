
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
#ifndef CHAINTABLE_H
#define CHAINTABLE_H
class View;
#include"view.h"
class Whire;
#include"whire.h"
#include<qobject.h>
#include<qtablewidget.h>
#include<qinputdialog.h>
#include"qheaderview.h"

class ChainTable  : public QTableWidget
{
	Q_OBJECT

public:
	ChainTable();
	~ChainTable();
	View* view=nullptr;
	void AdddPortSL();
	void AddChain();
public slots:
	void UpdateTable();
	void CellChange(int row, int column);
	void CellClck(int row, int colum);
protected:
	QMetaObject::Connection m_connection;
};
#endif
