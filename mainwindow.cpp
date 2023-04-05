#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLayout* lay= new QGridLayout();
    v=new View();
    QPainter painter;
    painter.begin(this);
    lay->addWidget(v);
    ui->centralwidget->setLayout(lay);

}

MainWindow::~MainWindow()
{
    delete ui;
}

