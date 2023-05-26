
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
#ifndef PIN_H
#define PIN_H

class Dot;
#include"Dot.h"
class Chain;
#include"chain.h"
class Port;
#include"port.h"
class NewPinWhire;
#include"NewPinWhire.h"
class AddPinComand;
#include"AddPinComand.h"
class RemovePinCommand;
#include"ui_pin.h"
#include"RemovePinCommand.h"
#include<QThread>
#include<qgraphicsproxywidget.h>
#include<QColorDialog>
#include<QLineEdit>
namespace Ui {
class Pin;
}

class Pin : public QLineEdit
{
    Q_OBJECT

public:
    explicit Pin(Port* port,bool bl=true,QLineEdit *parent = nullptr);
    ~Pin();
    int index();
    const QString name();
    void name(QString name);
public slots:
    void Update();
signals:
    void updSignal();
public:
    void EmitUpd(bool dotold=false);
    NewPinWhire* getpinWhire();
    Port* parCon;
    virtual Dot* dot(bool recalc = false);
    virtual void dot(Dot* d);
private:
    void mousePressEvent(QMouseEvent* event) override;
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dropEvent(QDropEvent* event) override;
    void dragMoveEvent(QDragMoveEvent* event) override;
public:
    Dot* coredot();

    qreal x();
    qreal y();
    void pinWhire(bool show=true);
    void PinWUpd();
    Chain* chain;
    AddPinComand* command=nullptr;
protected:
    virtual QMenu* ContextMenu();
    Ui::Pin *ui;

    bool upd = false; 
public slots:
    void RemoveFromChain();
    void Remove();
protected slots:
    virtual void showContextMenu(const QPoint& pos);
    void ChangeColor();


private:
    bool updaterbl;
    Dot* d;
    Dot* cored;
    NewPinWhire* pinW;
    QThread* thread;
    QString _name;

};

#endif // PIN_H
