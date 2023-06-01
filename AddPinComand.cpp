#include "AddPinComand.h"
#include"mygraphicsscene.h"
#include"pin.h"
#include"port.h"
#include"AddComand.h"
#include"proxyrectport.h"
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
	qDebug() << "Undo " << "AddPin "<< qint64(pn)<<"Com "<<qint64(this);
	name = pn->name();
	delete pn;
}

void AddPinComand::redo()
{
	pn = prt->p->addPin(name);
	qDebug() << "Redo " << "AddPin " << qint64(pn) << "Com " << qint64(this);
	pn->command = this;
	
}
