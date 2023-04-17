#include "mainwindow.h"

#include<qtabwidget.h>
#include"chaintable.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTabWidget* tabw = new QTabWidget();
    QWidget* w = new QWidget();
    QGridLayout* lay = new QGridLayout();
    v = new View();
    minima = new minimap(v);
    QPainter painter;
    painter.begin(this);
    lay->addWidget(v);
    lay->addWidget(minima);
    ui->centralwidget->setLayout(lay);
    lay->addWidget(v, 1, 0, 1, 1);
    minima->raise();
    lay->addWidget(minima, 1, 0, Qt::AlignBottom);
    w->setLayout(lay);
    tabw->addTab(w, "1");
    this->setCentralWidget(tabw);
    auto table = new ChainTable();
    tabw->addTab(table, "2");

    connect(tabw, SIGNAL(currentChanged(int)), table, SLOT(UpdateTable()));
    auto bar = new QMenuBar();
    setMenuBar(bar);
    auto m = new QMenu("View", this);
    QAction* actionNew = new QAction(tr("hide"), this);
    actionNew->setShortcutVisibleInContextMenu(true);
    connect(actionNew, SIGNAL(triggered()), this, SLOT(hidemMap()));
    m->addAction(actionNew);
    actionNew->setCheckable(true);
    bar->addMenu(m);
    hidemMap();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hidemMap()
{

    if (minima->isHidden())
        minima->show();
    else
        minima->hide();
}

