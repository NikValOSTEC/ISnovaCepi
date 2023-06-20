#include "RemovePinCommand.h"
#include"pin.h"
#include"mygraphicsscene.h"
#include"port.h"
#include"proxyrectport.h"
#include"AddPinComand.h"
#include"RemovePinCommand.h"
#include"AddComand.h"
RemovePinCommand::RemovePinCommand(Pin* p)
{
	pinc = p->command;
	pin = p;
	prt = p->parCon;
	((MYGraphicsScene*)prt->proxy()->scene())->Mview->stackPush(this);
}

RemovePinCommand::~RemovePinCommand()
{

}

void RemovePinCommand::undo()
{
	pinc->pn = pinc->prt->p->addPin(name, pos);
	pinc->pn->command = pinc;
}

void RemovePinCommand::redo()
{
	pos = pinc->pn->index();
	name = pinc->pn->name();
	delete pinc->pn;
}
