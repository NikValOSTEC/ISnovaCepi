
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
#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H
class View;
#include"view.h"
#include<QGraphicsScene>

class MYGraphicsScene : public QGraphicsScene
{
public:
    View* Mview;
    int _scale = 100;
    explicit MYGraphicsScene(QObject *parent = nullptr);
private:
    int lastselected = 0;
};

#endif // MYGRAPHICSSCENE_H
