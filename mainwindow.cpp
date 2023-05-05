#include "mainwindow.h"
#include<qtabwidget.h>
#include"chaintable.h"
#include"PortTwmplateObject.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTabWidget* tabw = new QTabWidget();
    QWidget* w = new QWidget();
    QGridLayout* lay = new QGridLayout();
    v = new View();
    QWidget* central = new QWidget();
    central->setSizePolicy(QSizePolicy::QSizePolicy::Expanding, QSizePolicy::Expanding);
    TempList = new QScrollArea;
    QHBoxLayout* layou = new QHBoxLayout();
    central->setLayout(layou);
    TempList->setWidget(central);
    TempList->setWidgetResizable(true);
    TempList->widget()->layout()->setAlignment(Qt::AlignLeft);
    central->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    TempList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    TempList->setFixedHeight(140);
    lay->addWidget(TempList);

    auto plusbt = new QPushButton("+");
    plusbt->setFixedSize(QSize(50, 50));

    connect(plusbt, SIGNAL(clicked()), this, SLOT(AddTemp()));
    TempList->widget()->layout()->addWidget(plusbt);
    minima = new minimap(v);
    lay->addWidget(v, 1, 0, 1, 1);
    minima->raise();
    lay->addWidget(minima, 1, 0, Qt::AlignBottom);
    w->setLayout(lay);
    tabw->addTab(w, "1");
    this->setCentralWidget(tabw);
    auto table = new ChainTable();
    table->view = v;
    tabw->addTab(table, "2");

    connect(tabw, SIGNAL(currentChanged(int)), table, SLOT(UpdateTable()));
    auto bar = new QMenuBar();
    setMenuBar(bar);
    auto m = new QMenu("View", this);
    QAction* actionNew = new QAction(tr("Hide Map"), this);
    actionNew->setShortcutVisibleInContextMenu(true);
    connect(actionNew, SIGNAL(triggered()), this, SLOT(hidemMap()));
    m->addAction(actionNew);
    actionNew->setCheckable(true);
    bar->addMenu(m);

    m = new QMenu("Edit", this);
    actionNew = new QAction(tr("Undo"), this);
    actionNew->setShortcutVisibleInContextMenu(true);
    connect(actionNew, SIGNAL(triggered()), this->v, SLOT(stckUndo()));
    m->addAction(actionNew);
    actionNew = new QAction(tr("Redo"), this);
    actionNew->setShortcutVisibleInContextMenu(true);
    connect(actionNew, SIGNAL(triggered()), this->v, SLOT(stckRedo()));
    m->addAction(actionNew);
    bar->addMenu(m);


    hidemMap();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddTemp(Port* p)
{
    auto tmp=new PortTwmplateObject();
    tmp->templ->name(p->name());
    foreach(auto pn, p->pins())
    {
        tmp->templ->addPin(pn->name());
    }
    tmp->setFixedSize(QSize(70, 100));
    TempList->widget()->layout()->addWidget(tmp);
}

void MainWindow::hidemMap()
{

    if (minima->isHidden())
        minima->show();
    else
        minima->hide();
}

