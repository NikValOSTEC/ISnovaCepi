
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
#ifndef PINTEMPLATE_H
#define PINTEMPLATE_H
class Pin;
#include "Pin.h"
class Port;
#include"port.h"

class PinTemplate  : public Pin
{
	Q_OBJECT

public:
	PinTemplate(Port* p);
    
//    void initializeGL() {

//    }
//    void paintGL() {
//        glClearColor(1.f, 0.f, 0.f, 1.f);
//        glClear(GL_COLOR_BUFFER_BIT);
//    }
    ~PinTemplate();
};
#endif
