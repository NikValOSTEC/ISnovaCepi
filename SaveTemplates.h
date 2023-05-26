
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
#ifndef SAVETEMPLATES_H
#define SAVETEMPLATES_H
class QLineEditFocusOutSignal;
class PortTwmplateObject;
#include"QLineEditFocusOutSignal.h"
#include <QObject>
#include"PortTwmplateObject.h"
#include <QFile>
#include <QTextStream>

class SaveTemplates  : public QObject
{
	Q_OBJECT

public:
	SaveTemplates(QObject *parent);
	~SaveTemplates();
	static void Save(QString path, PortTwmplateObject o);
};
#endif
