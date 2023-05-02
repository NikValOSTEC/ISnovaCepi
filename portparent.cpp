#include "portparent.h"
#include "qgraphicsproxywidget.h"
#include "qmenu.h"
#include "ui_port.h"
#include <QGridLayout>
#include<QVBoxLayout>
#include"mygraphicsscene.h"
class RemovePortComand;
#include"RemoveComand.h"
class RemovePinCommand;
#include"RemovePinCommand.h"
PortParent::PortParent() :
    QOpenGLWidget(),
    ui(new Ui::Port)
{
    ui->setupUi(this);
    ui->PinsList->layout()->setAlignment(Qt::AlignTop);
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)),
        this, SLOT(showContextMenu(QPoint)));
}



PortParent::~PortParent()
{

}

QString PortParent::name()
{
    return ui->Name->text();
}

void PortParent::name(QString str)
{
    ui->Name->setText(str);
}

QVector<Pin*> PortParent::pins()
{
    auto objs = ui->PinsList->children().toVector();
    QVector<Pin*> res = QVector<Pin*>();
    foreach(auto vr, objs)
    {
        auto pn = dynamic_cast<Pin*>(vr);
        if (pn)
            res.append(pn);
    }
    return res;
}





void PortParent::on_pushButton_clicked()
{

}

void PortParent::showContextMenu(const QPoint& pos)
{
    QPoint globalPos = this->mapToGlobal(pos);
    ContextMenu()->exec(globalPos);
}

QMenu* PortParent::ContextMenu()
{
    QMenu* myMenu = new QMenu();
    myMenu->addAction("addPin", this, SLOT(addPinSl()));
    QAction* actionDel = new QAction(tr("delete"), this);
    connect(actionDel, SIGNAL(triggered()), this, SLOT(RemoveSL()));
    actionDel->setMenuRole(QAction::MenuRole::QuitRole);
    myMenu->addAction(actionDel);
    return myMenu;
}

Pin* PortParent::addPin(QString name, int index)
{
    auto pn = new Pin();
    pn->name(name);
    ((QVBoxLayout*)(this->ui->PinsList->layout()))->insertWidget(index, pn);
    auto rec = this->_proxy->geometry();
    rec.setHeight(60 + this->height());
    this->_proxy->geometry(rec);
    return pn;
}


Pin* PortParent::addPinSl(QString name)
{
    return addPin();
}

void PortParent::RemoveSL()
{
    delete this;
}

void PortParent::Remove()
{
    auto x = graphicsProxyWidget()->parentItem();
    delete (x);
}

void PortParent::Update(bool updF)
{
    foreach(auto p, pins())
    {
        p->EmitUpd(updF);
    }
}

ProxyRectPort* PortParent::proxy()
{
    return _proxy;
}

void PortParent::proxy(ProxyRectPort* prox)
{
    _proxy = prox;
}

void PortParent::setFilter()
{

}

