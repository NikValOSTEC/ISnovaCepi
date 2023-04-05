#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ui_mainwindow.h"
#include <QGridLayout>
#include"proxyrectport.h"
#include "port.h"
#include <QGraphicsLineItem>
#include<QGraphicsProxyWidget>
#include"view.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    View* v;
};
#endif // MAINWINDOW_H
