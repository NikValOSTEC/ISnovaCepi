#include "AddPinComand.h"
#include"mygraphicsscene.h"
#include"pin.h"
#include"port.h"
#include"AddComand.h"
#include"proxyrectport.h"
#include "MessageHandler.h"
AddPinComand::AddPinComand(Port *p,QString nae,bool rea)
{
	real = rea;
	prt = p->adcom;
	name = nae;
	((MYGraphicsScene*)(p->proxy()->scene()))->Mview->stackPush(this);
	myMessageHandler( "AddPin");
}

AddPinComand::~AddPinComand()
{
	myMessageHandler( "~AddPin");
}

void AddPinComand::undo()
{
	name = pn->name();
	delete pn;
	myMessageHandler( "AddPinUndo");
}

void AddPinComand::redo()
{
	pn = prt->p->addPin(name,-1,real);
	pn->command = this;
	prt->p->proxy()->Update(true);
	myMessageHandler( "AddPinRedo");
	
}
