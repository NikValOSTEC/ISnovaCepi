
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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
class View;
class minimap;
class ChainTable;
#include"chaintable.h"
#include"ui_mainwindow.h"
#include"view.h"
#include"minimap.h"
#include<qscrollarea.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void AddTemp(Port* p=new Port());
public slots:
    void hidemMap();
private:
    Ui::MainWindow *ui;
    View* v;
    minimap* minima;
    QScrollArea* TempList;
};
#endif // MAINWINDOW_H
