#include "AddWhireCommand.h"

AddWhireCommand::AddWhireCommand(Pin* p11,Pin*p22)
{
	this->p1 = p11;
	this->p2 = p22;
	whire = nullptr;
	((MYGraphicsScene*)(p11->parCon->proxy()->scene()))->Mview->stack->push(this);
}

AddWhireCommand::~AddWhireCommand()
{}

void AddWhireCommand::undo()
{
	delete whire;
}

void AddWhireCommand::redo()
{
	whire = new Whire(p1, p2);
}
