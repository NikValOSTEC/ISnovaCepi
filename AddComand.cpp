#include "AddComand.h"
#include"view.h"
#include"port.h"
#include"proxyrectport.h"
#include"mygraphicsscene.h"
AddComand::AddComand(View* v,int x,int y,QString name)
{

    x = floor(x / 25) * 25;
    y = floor(y / 25) * 25;
    qDebug() << "pos" << x << "  " << y;
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
    xx = p->proxy()->geometry().x();
    yy = p->proxy()->geometry().y();
    name = p->name();
    p->Remove();
}

void AddComand::redo()
{
    qDebug() << "Redo " << "Port  "<<xx<<" "<<yy;
    p = new Port(this);
    p->adcom = this;
    p->name(name);
    ProxyRectPort* proxyControl = new ProxyRectPort(p);
    proxyControl->geometry(QRectF(xx, yy-25, p->width(), 25 + p->height()));
    v->GScene()->addItem(proxyControl);
    QGraphicsProxyWidget* const proxy = v->GScene()->addWidget(p);
    proxy->setPos(xx, yy);
    proxy->setParentItem(proxyControl);
}
