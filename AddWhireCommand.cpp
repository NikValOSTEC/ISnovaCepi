#include "AddWhireCommand.h"
#include"mygraphicsscene.h"
#include"AddPinComand.h"
#include"pin.h"
#include"port.h"
#include"NewWhire.h"
#include"proxyrectport.h"
#include"Dot.h"
#include<QDebug>
#include "MessageHandler.h"
AddWhireCommand::AddWhireCommand(AddPinComand* p11, AddPinComand*p22)
{
	this->p1 = p11;
	this->p2 = p22;
	whire = nullptr;
	auto MV = ((MYGraphicsScene*)(p11->pn->parCon->proxy()->scene()))->Mview;
	MV->stackPush(this);
	myMessageHandler( "AddWhire");
}

AddWhireCommand::~AddWhireCommand()
{
	myMessageHandler( "~AddWhire");
}

void AddWhireCommand::undo()
{
	delete whire;
	if (p1->pn->chain != nullptr)
	{
		if (p1->pn->dot()->whrscount()< 1)
		{
			p1->pn->RemoveFromChain();
		}
	}

	if (p2->pn->chain != nullptr)
	{
		if (p2->pn->dot()->whrscount() < 1)
		{
			p2->pn->RemoveFromChain();
		}
	}
	myMessageHandler("AddWhireUndo");
}

void AddWhireCommand::redo()
{
	try { whire = new NewWhire(p1->pn, p2->pn, this); }
	catch (_exception exp)
	{
		if (exp.type == 9999)
		{
			delete whire;
		}
	}
	myMessageHandler("AddWhireRedo");
}
