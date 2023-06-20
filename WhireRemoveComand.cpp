#include "WhireRemoveComand.h"
#include"NewWhire.h"
#include"pin.h"
#include"mygraphicsscene.h"
#include"AddWhireCommand.h"
#include"WhireRemoveComand.h"
#include"AddPinComand.h"
#include"RemovePinCommand.h"
#include"chain.h"
#include"Dot.h"
#include<QDebug>
WhireRemoveComand::WhireRemoveComand(NewWhire* w)
{
	p1 = w->p1->command;
	p2 = w->p2->command;
	wc = w->command;
	((MYGraphicsScene*)(((CustomColliderLineRecoursive*)w)->scene()))->Mview->stackPush(this);
}

WhireRemoveComand::~WhireRemoveComand()
{
	
}

void WhireRemoveComand::undo()
{
	if (p1->pn->chain != nullptr)
	{
		p1->pn->chain->pins.removeOne(p1->pn);
		p1->pn->chain = nullptr;
	}
	wc->whire=new NewWhire(p1->pn, p2->pn,wc);
}

void WhireRemoveComand::redo()
{
	delete wc->whire;
	if (p1->pn->chain != nullptr)
	{
		if (p1->pn->dot()->whrscount() < 1)
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
	
}
