#include "WhireRemoveComand.h"

WhireRemoveComand::WhireRemoveComand(Whire* w)
{
	p1 = w->p1->command;
	p2 = w->p2->command;
	wc = w->command;
	((MYGraphicsScene*)w->scene())->Mview->stackPush(this);
}

WhireRemoveComand::~WhireRemoveComand()
{
	
}

void WhireRemoveComand::undo()
{
	qDebug() << "Undo " << "WRem";
	if (p1->pn->chain != nullptr)
	{
		qDebug() << p1->pn->chain->pins.count();
		p1->pn->chain->pins.removeOne(p1->pn);
		p1->pn->chain = nullptr;
	}
	wc->whire=new Whire(p1->pn, p2->pn,wc);
}

void WhireRemoveComand::redo()
{
	qDebug() << "Redo " << "WRem";
	delete wc->whire;
}
