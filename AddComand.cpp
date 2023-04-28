#include "AddComand.h"
#include"port.h"
AddComand::AddComand(View* v,int x,int y,QString name)
{

    xx = x;
    yy = y;
    this->v = v;    

    v->stackPush(this);
    this->name = name;
}

AddComand::~AddComand()
{}

void AddComand::undo()
{
    qDebug() << "Undo " << "Port";
    xx = p->proxy()->pos().x();
    yy = p->proxy()->pos().y();
    name = p->name();
    p->Remove();
}

void AddComand::redo()
{
    qDebug() << "Redo " << "Port";
    p = new Port(this);
    p->adcom = this;
    p->name(name);
    ProxyRectPort* proxyControl = new ProxyRectPort(p);
    proxyControl->geometry(QRectF(xx, yy + p->height(), p->width(), 30 + p->height()));
    v->GScene()->addItem(proxyControl);
    QGraphicsProxyWidget* const proxy = v->GScene()->addWidget(p);
    proxy->setPos(xx, yy + proxyControl->boundingRect().height());
    proxy->setParentItem(proxyControl);
}
