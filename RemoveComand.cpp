#include "RemoveComand.h"

RemovePortComand::RemovePortComand(Port* port )
{
	addcom = port->adcom;
	((MYGraphicsScene*)(port->proxy()->scene()))->Mview->stackPush(this);
    v = addcom->v;
}

RemovePortComand::~RemovePortComand()
{}

void RemovePortComand::undo()
{
	addcom->p = new Port(addcom);
    addcom->p->adcom = addcom;
    addcom->p->name(name);
    ProxyRectPort* proxyControl = new ProxyRectPort(addcom->p);
    v->GScene()->addItem(proxyControl);
    QGraphicsProxyWidget* const proxy = v->GScene()->addWidget(addcom->p);
    proxy->setParentItem(proxyControl);
}

void RemovePortComand::redo()
{
	addcom->p->Remove();
}
