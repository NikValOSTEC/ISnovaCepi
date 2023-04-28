#include "AddPinComand.h"

AddPinComand::AddPinComand(Port *p,QString nae)
{
	prt = p->adcom;
	name = nae;
	((MYGraphicsScene*)(p->proxy()->scene()))->Mview->stackPush(this);
}

AddPinComand::~AddPinComand()
{}

void AddPinComand::undo()
{
	qDebug() << "Undo " << "AddPin";
	name = pn->name();
	delete pn;
}

void AddPinComand::redo()
{
	qDebug() << "Redo " << "AddPin";
	pn = prt->p->addPin(name);
	pn->command = this;
	
}
