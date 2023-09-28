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
#include "MessageHandler.h"
WhireRemoveComand::WhireRemoveComand(NewWhire* w)
{
	const void* address = static_cast<const void*>(w);
	QString addressString;
	QTextStream addressStream(&addressString);
	addressStream << "WhireRemoveCommandHead    " << address;    
	std::string str = addressString.toStdString();
	const char* p = str.c_str();
	myMessageHandler(p,QtWarningMsg);
	const void* addressp1 = static_cast<const void*>(w->p1);
	const void* addressp2 = static_cast<const void*>(w->p2);	
	QString addressString2;
	QTextStream addressStream2(&addressString2);
	addressStream2 << "Pins    " << addressp1<<"      "<<addressp2;
	std::string str2 = addressString2.toStdString();
	p = str2.c_str();
	myMessageHandler(p, QtWarningMsg);

	p1 = w->p1->command;
	p2 = w->p2->command;
	wc = w->command;
	((MYGraphicsScene*)(w->scene()))->Mview->stackPush(this);
	myMessageHandler( "WhireRemoveCommand");
}

WhireRemoveComand::~WhireRemoveComand()
{
	myMessageHandler( "~WhireRemoveCommand");
}

void WhireRemoveComand::undo()
{
	if (p1->pn->chain != nullptr)
	{
		p1->pn->chain->pins.removeOne(p1->pn);
		p1->pn->chain = nullptr;
	}
	wc->whire=new NewWhire(p1->pn, p2->pn,wc);

	myMessageHandler( "WhireRemoveCommandUndo");
}

void WhireRemoveComand::redo()
{
	delete wc->whire;
	if (p1->pn->chain != nullptr)
	{
		if (p1->pn->dot()->whires.count() < 1)
		{
			p1->pn->RemoveFromChain();
		}
	}

	if (p2->pn->chain != nullptr)
	{
		if (p2->pn->dot()->whires.count() < 1)
		{
			p2->pn->RemoveFromChain();
		}
	}

	myMessageHandler( "WhireRemoveCommandRedo");
}
