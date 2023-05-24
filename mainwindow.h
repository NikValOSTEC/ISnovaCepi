#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"ui_mainwindow.h"
class Port;
#include"port.h"
class View;
#include"view.h"
class minimap;
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
