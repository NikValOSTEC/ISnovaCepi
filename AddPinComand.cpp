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
	name = pn->name();
	delete pn;
}

void AddPinComand::redo()
{
	pn = prt->p->addPin(name);
	pn->command = this;
	prt->p->proxy()->Update(true);
	
}
