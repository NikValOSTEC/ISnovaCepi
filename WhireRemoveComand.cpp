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
	wc->whire=new Whire(p1->pn, p2->pn,wc);
}

void WhireRemoveComand::redo()
{
	qDebug() << "Redo " << "WRem";
	delete wc->whire;
}
