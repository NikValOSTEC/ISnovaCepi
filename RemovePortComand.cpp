#include "RemovePortComand.h"
#include"mygraphicsscene.h"
#include"port.h"
#include"AddComand.h"
#include"proxyrectport.h"
#include "MessageHandler.h"

RemovePortComand::RemovePortComand(Port* port )
{
	addcom = port->adcom;
	((MYGraphicsScene*)(port->proxy()->scene()))->Mview->stackPush(this);
    v = addcom->v;
    myMessageHandler( "RemovePortCommand");
}

RemovePortComand::~RemovePortComand()
{}

void RemovePortComand::undo()
{
	addcom->p = new Port(addcom);
    addcom->p->adcom = addcom;
    addcom->p->name(name);
    ProxyRectPort* proxyControl = new ProxyRectPort(addcom->p);
    proxyControl->geometry(QRectF(xx, yy-30, addcom->p->width(), 30 + addcom->p->height()));
    v->GScene()->addItem(proxyControl);
    QGraphicsProxyWidget* const proxy = v->GScene()->addWidget(addcom->p);
    proxy->setPos(xx, yy);
    proxy->setParentItem(proxyControl);
    myMessageHandler( "RemovePortCommandUndo");
}

void RemovePortComand::redo()
{
    xx = addcom->p->proxy()->geometry().x();
    yy = addcom->p->proxy()->geometry().y();
	addcom->p->Remove();
    myMessageHandler( "RemovePortCommandRedo");
}
