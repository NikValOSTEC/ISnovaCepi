#include "AddComand.h"

AddComand::AddComand(View* v,int x,int y,QString name)
{

    xx = x;
    yy = y;
    this->v = v;    
    /*p = new Port();
    ProxyRectPort* proxyControl = new ProxyRectPort(p);
    proxyControl->geometry(QRectF(x, y + p->height(), p->width(), 30 + p->height()));
    v->GScene()->addItem(proxyControl);
    QGraphicsProxyWidget* const proxy = v->GScene()->addWidget(p);
    proxy->setPos(x, y + proxyControl->boundingRect().height());
    proxy->setParentItem(proxyControl);*/
    v->stack->push(this);
    this->name = name;
}

AddComand::~AddComand()
{}

void AddComand::undo()
{
    xx = p->proxy()->pos().x();
    yy = p->proxy()->pos().y();
    name = p->name();
    p->Remove();
}

void AddComand::redo()
{
    p = new Port();
    p->name(name);
    ProxyRectPort* proxyControl = new ProxyRectPort(p);
    proxyControl->geometry(QRectF(xx, yy + p->height(), p->width(), 30 + p->height()));
    v->GScene()->addItem(proxyControl);
    QGraphicsProxyWidget* const proxy = v->GScene()->addWidget(p);
    proxy->setPos(xx, yy + proxyControl->boundingRect().height());
    proxy->setParentItem(proxyControl);
}
