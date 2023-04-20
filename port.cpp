#include "port.h"
#include "qgraphicsproxywidget.h"
#include "qmenu.h"
#include "ui_port.h"
#include <QGridLayout>
#include"mygraphicsscene.h"
Port::Port(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Port)
{
    ui->setupUi(this);
    ui->PinsList->layout()->setAlignment(Qt::AlignTop);
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)),
        this, SLOT(showContextMenu(QPoint)));
    portsVector.append(this);
}

Port::~Port()
{
    for (int i = 0; i < ui->PinsList->layout()->count(); ++i)
    {
        QWidget* w = ui->PinsList->layout()->itemAt(i)->widget();
        delete(static_cast<Pin*>(w));
    }
    delete ui;
    portsVector.removeOne(this);

}

QString Port::name()
{
    return ui->Name->text();
}

void Port::name(QString str)
{
    ui->Name->setText(str);
}

QVector<Pin*> Port::pins()
{
    auto objs= ui->PinsList->children().toVector();
    QVector<Pin*> res = QVector<Pin*>();
    foreach(auto vr, objs)
    {
        auto pn = dynamic_cast<Pin*>(vr);
        if(pn)
            res.append(pn);
    }
    return res;
}





void Port::on_pushButton_clicked()
{

}

void Port::showContextMenu(const QPoint &pos)
{
    QPoint globalPos = this->mapToGlobal(pos);
    ContextMenu()->exec(globalPos);
}

QMenu *Port::ContextMenu()
{
    QMenu* myMenu = new QMenu();
    myMenu->addAction("addPin", this, SLOT(addPin()));
    QAction* actionDel = new QAction(tr("delete"), this);
    connect(actionDel, SIGNAL(triggered()), this, SLOT(Remove()));
    actionDel->setMenuRole(QAction::MenuRole::QuitRole);
    myMenu->addAction(actionDel);
    return myMenu;
}

Pin* Port::addPin(QString name)
{
    auto pn = new Pin(this);
    pn->name(name);
    this->ui->PinsList->layout()->addWidget(pn);
    auto rec=this->_proxy->geometry();
    rec.setHeight(60+this->height());
    this->_proxy->geometry(rec);
    return pn;
}

void Port::Remove()
{
    auto x=graphicsProxyWidget()->parentItem();
    delete (x);
}

void Port::Update()
{
    foreach (auto p, pins())
    {
        p->Update();
    }
}

ProxyRectPort* Port::proxy()
{
    return _proxy;
}

void Port::proxy(ProxyRectPort *prox)
{
    _proxy=prox;
}

void Port::setFilter()
{

}

