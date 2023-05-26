
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
#ifndef GVIEW_H
#define GVIEW_H
#include<qobject.h>
class MYGraphicsScene;
class QGraphicsView;
class PortTwmplateObject;
#include"qgraphicsview.h"
#include"mygraphicsscene.h"
#include<qdrag.h>
#include<qevent.h>
#include<QMimeData>
#include"PortTwmplateObject.h"

class GView  : public QGraphicsView
{

public:
	GView(QObject *parent);
	~GView();

	MYGraphicsScene* GScene();
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
	void dropEvent(QDropEvent* event)override;
	void dragEnterEvent(QDragEnterEvent* event) override;
	void dragMoveEvent(QDragMoveEvent* event) override;
	int lastselected = 0;
};
#endif
