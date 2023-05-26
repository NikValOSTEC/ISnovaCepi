
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
#ifndef PORTTEMPLATE_H
#define PORTTEMPLATE_H
class Port;
#include"port.h"
class Pin;
#include"pin.h"
class PinTemplate;
#include"PinTemplate.h"
#include"qobject.h"
#include <qopenglfunctions.h>

namespace Ui {
	class Port;
}

class PortTemplate  : public Port
{
	Q_OBJECT

public:
	PortTemplate();
	Pin* addPinn(QString name = "", int index = -1);
	~PortTemplate();
private slots:
	Pin* addPinSl(QString name = "");
	void RemoveSL();

//	void initializeGL()
//	{

//		QOpenGLFunctions* f = QOpenGLContext::currentContext()->functions();
//		f->glClearColor(240, 240, 240, 1.0f);
//	}

//	void paintGL()
//	{
//		QOpenGLFunctions* f = QOpenGLContext::currentContext()->functions();
//		f->glClearColor(240, 240, 240, 1.0f);
//		f->glClear(GL_COLOR_BUFFER_BIT);
//	}


    virtual QMenu* ContextMenu();
};
#endif
