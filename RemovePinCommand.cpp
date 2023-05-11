#include "RemovePinCommand.h"

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
	qDebug()<<"RemPin "<<"Und "<<qint64((pinc->pn))<<"Com "<< qint64(pinc);
	pinc->pn = pinc->prt->p->addPin(name, pos);
	pinc->pn->command = pinc;
}

void RemovePinCommand::redo()
{
	qDebug() << "RemPin " << "Red " << qint64((pinc->pn)) << "Com " << qint64(pinc);
	pos = pinc->pn->index();
	name = pinc->pn->name();
	delete pinc->pn;
}
