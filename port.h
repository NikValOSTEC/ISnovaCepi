#pragma once
#ifndef PORT_H
#define PORT_H
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
#include"AddComand.h"
class ProxyRectPort;
#include"proxyrectport.h"
class Pin;
#include"Pin.h"
class RemovePortComand;
#include"RemovePortComand.h"
#include"ui_port.h"
#include"qobject.h"
#include<QMenu>
#include<qwidget.h>
namespace Ui {
class Port;
}

class Port : public QWidget
{
    Q_OBJECT

public:
    explicit Port(AddComand* com, QWidget *parent = nullptr);
    Port();
    virtual ~Port();

    QString name();
    void name(QString str);
    static QVector<Port*> portsVector;
    QVector<Pin*>pins();
    AddComand* adcom;
    void Remove();
    virtual Pin* addPin(QString name = "", int index = -1);
    void showContextMenu(const QPoint& pos);
private slots:
    void on_pushButton_clicked();
    Pin* addPinSl(QString name="");
    void RemoveSL();
public slots:
    void Update(bool updF=false);
    ProxyRectPort* proxy();
    void proxy(ProxyRectPort*prox);
    void setFilter();


protected:
    Ui::Port *ui;
    virtual QMenu* ContextMenu();
    ProxyRectPort* _proxy;
};

#endif // PORT_H
