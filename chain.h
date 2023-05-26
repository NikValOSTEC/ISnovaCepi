
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
#ifndef CHAIN_H
#define CHAIN_H
#include<qobject.h>
class Pin;
#include"Pin.h"
class WhireRemoveComand;
#include<qcolor.h>
#include"WhireRemoveComand.h"
class Chain :public QObject
{
    Q_OBJECT
public:
    Chain();
    ~Chain();
    void AddPin(Pin* p);
    void RemovePin(Pin* p);
    static QVector<Chain*> chains;
    QVector<Pin*> pins;
    void moveToChain(Chain* chain); 
    QColor color;
};
#endif
