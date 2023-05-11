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
	qDebug() << "Undo " << "AddWhire " << qint64(whire) << " p1" << qint64(p1) << " p2" << qint64(p2);
	delete whire;
	if (p1->pn->chain != nullptr)
	{
		if (p1->pn->Dot()->whires.count() < 1)
		{
			p1->pn->RemoveFromChain();
		}
	}

	if (p2->pn->chain != nullptr)
	{
		if (p2->pn->Dot()->whires.count() < 1)
		{
			p2->pn->RemoveFromChain();
		}
	}
}

void AddWhireCommand::redo()
{
	whire=new Whire(p1->pn, p2->pn,this);
	qDebug() << "Redo " << "AddWhire " << qint64(whire)<<" p1"<<qint64(p1) << " p2" << qint64(p2);
}
