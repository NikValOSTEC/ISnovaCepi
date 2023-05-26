
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
#ifndef MINIMAP_H
#define MINIMAP_H
class View;
#include"qevent.h"
#include<qgraphicsview.h>
#include"view.h"
class minimap  : public QGraphicsView
{
	Q_OBJECT

public:
	minimap(View *v);
	void mouseMoveEvent(QMouseEvent* event)override;
	void mouseReleaseEvent(QMouseEvent* event)override;
	void mousePressEvent(QMouseEvent* event)override;
	void mouseDoubleClickEvent(QMouseEvent* event) override;
#if QT_CONFIG(wheelevent)
	void wheelEvent(QWheelEvent* e);
#endif

	~minimap();
	View* v;
	float sclX, sclY;
public slots:
	void rescale();
};
#endif
