#include "port.h"
#include"pin.h"
#include"proxyrectport.h"
#include"AddPinComand.h"
#include"RemovePortComand.h"
#include"RemovePinCommand.h"
qreal Port::x()
{
    return _proxy->boundingRect().center().x();
}
qreal Port::y()
{
    return _proxy->boundingRect().center().y();
}
Port::Port(AddComand* com,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Port)
{
    ui->setupUi(this);
    ui->PinsList->layout()->setAlignment(Qt::AlignTop);
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)),
        this, SLOT(showContextMenu(QPoint)));
    portsVector.append(this);
    adcom = com;
    spacer = nullptr;
}

Port::Port():
    ui(new Ui::Port)
{
    ui->setupUi(this);
    ui->PinsList->layout()->setAlignment(Qt::AlignTop);
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)),
        this, SLOT(showContextMenu(QPoint)));
}



Port::~Port()
{
    delete ui;

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
    QPoint globalPos = QCursor::pos();
    ContextMenu()->exec(globalPos);
}

QMenu *Port::ContextMenu()
{
    QMenu* myMenu = new QMenu();
    myMenu->addAction("addPin", this, SLOT(addPinSl()));
    QAction* actionDel = new QAction(tr("delete"), this);
    connect(actionDel, SIGNAL(triggered()), this, SLOT(RemoveSL()));
    actionDel->setMenuRole(QAction::MenuRole::QuitRole);
    myMenu->addAction(actionDel);
    return myMenu;
}

Pin* Port::addPin(QString name, int index, bool bl)
{
    auto pn = new Pin(this,bl);
    pn->name(name);
    ((QVBoxLayout*)(this->ui->PinsList->layout()))->insertWidget(index,pn);
    if (bl)
    {
        auto rec = this->_proxy->geometry();
        rec.setHeight(50 + this->height());
        this->_proxy->geometry(rec);
        if (spacer == nullptr)
        {
            auto h = (floor(pn->y() / 25) * 25 + 25) - pn->y();
            spacer = new QSpacerItem(
                this->ui->PinsList->width(), h);
            ((QVBoxLayout*)(this->ui->PinsList->layout()))->insertItem(0, spacer);
        }
    }
    return pn;
}


Pin* Port::addPinSl(QString name)
{
    auto x=new AddPinComand(this,name);
    return x->pn;
}

void Port::RemoveSL()
{
    new RemovePortComand(this);
}

void Port::Remove()
{
    auto x=graphicsProxyWidget()->parentItem();
    foreach(auto p, pins())
    {
        new RemovePinCommand(p);
    }
    portsVector.removeOne(this);
    delete (x);
}

void Port::Update(bool updF)
{
    foreach (auto p, pins())
    {
        p->EmitUpd(updF);
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

