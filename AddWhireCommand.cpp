#include "AddWhireCommand.h"

AddWhireCommand::AddWhireCommand(AddPinComand* p11, AddPinComand*p22)
{
	this->p1 = p11;
	this->p2 = p22;
	whire = nullptr;
	auto MV = ((MYGraphicsScene*)(p11->pn->parCon->proxy()->scene()))->Mview;
	MV->stackPush(this);
}

AddWhireCommand::~AddWhireCommand()
{}

void AddWhireCommand::undo()
{
	qDebug() << "Undo " << "AddWhire";
	delete whire;
}

void AddWhireCommand::redo()
{
	qDebug() << "Redo " << "AddWhire";
	whire=new Whire(p1->pn, p2->pn,this);
}
