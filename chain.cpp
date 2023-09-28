#include "chain.h"
#include"WhireRemoveComand.h"
#include"pin.h"
#include"AddWhireCommand.h"
#include"Dot.h"
#include"NewWhire.h"
#include"NewPinWhire.h"
#include "MessageHandler.h"
Chain::Chain():QObject()
{
	pins = QVector<Pin*>();
	chains.append(this);
	myMessageHandler( "Chain");
}

Chain::~Chain()
{
	chains.removeOne(this);
	myMessageHandler( "~Chain");
}

void Chain::AddPin(Pin* p)
{
	myMessageHandler("ChainAddPin");
	if (!pins.contains(p))
	{
		pins.append(p);
		p->chain = this;
		const void* address = static_cast<const void*>(p);
		QString addressString;
		QTextStream addressStream(&addressString);
		addressStream << "Pin Add" << address;
		std::string str = addressString.toStdString();
		const char* p = str.c_str();
		myMessageHandler(p, QtWarningMsg);
	}
}

void Chain::RemovePin(Pin* p)
{
	const void* address = static_cast<const void*>(p);
	QString addressString;
	QTextStream addressStream(&addressString);
	addressStream << "RemovePin  " << address;
	std::string str = addressString.toStdString();
	const char* pt = str.c_str();
	myMessageHandler(pt, QtWarningMsg);
	try
	{
		if (pins.removeOne(p))
		{
			const void* address = static_cast<const void*>(p);
			QString addressString;
			QTextStream addressStream(&addressString);
			addressStream << "Chain Remove Pin 1  " << address;
			std::string str = addressString.toStdString();
			const char* ssst = str.c_str();
			myMessageHandler(ssst, QtWarningMsg);
			p->getpinWhire()->ClearInside();
			p->chain = nullptr;
			auto whires = p->dot()->whires;
			for (int i = 0; i < whires.count(); i++)
			{
				address = static_cast<const void*>(whires[i]);
				addressString="";
				QTextStream addressStream(&addressString);
				addressStream << "Whire "<<i<<"   " << address;
				str = addressString.toStdString();
				ssst = str.c_str();
				myMessageHandler(ssst, QtWarningMsg);
			}
			if (pins.count() > 1)
			{
				for (int i = 0; i < whires.count(); i++)
				{
					if (whires[i]->p1 == p)
					{
						if (whires[i]->p2->dot()->whires.count() > 1)
						{
							const void* address = static_cast<const void*>(whires[i]->p2);
							QString addressString;
							QTextStream addressStream(&addressString);
							addressStream << "Chain Remove Pin 2 " << address;
							std::string str = addressString.toStdString();
							const char* ssst = str.c_str();
							myMessageHandler(ssst, QtWarningMsg);
							new WhireRemoveComand(whires[i]);
						}
						else
						{
							auto p2 = whires[i]->p2;
							const void* address = static_cast<const void*>(p2);
							QString addressString;
							QTextStream addressStream(&addressString);
							addressStream << "Chain Remove Pin 2 " << address;
							std::string str = addressString.toStdString();
							const char* ssst = str.c_str();
							myMessageHandler(ssst, QtWarningMsg);
							for (int j = 0; j < pins.count(); j++)
							{
								auto pn = pins[j];
								if (pn != p2)
								{
									p2->chain = nullptr;
									pins.removeOne(p2);
									new AddWhireCommand(pn->command, p2->command);
									new WhireRemoveComand(whires[i]);
									break;
								}
							}
						}

					}
					else if (whires[i]->p2 == p)
					{
						if (whires[i]->p1->dot()->whires.count() > 1)
						{
							const void* address = static_cast<const void*>(whires[i]->p1);
							QString addressString;
							QTextStream addressStream(&addressString);
							addressStream << "Chain Remove Pin 22 " << address;
							std::string str = addressString.toStdString();
							const char* ssst = str.c_str();
							myMessageHandler(ssst, QtWarningMsg);
							new WhireRemoveComand(whires[i]);
						}
						else
						{
							auto p1 = whires[i]->p1;
							const void* address = static_cast<const void*>(p1);
							QString addressString;
							QTextStream addressStream(&addressString);
							addressStream << "Chain Remove Pin 22 " << address;
							std::string str = addressString.toStdString();
							const char* ssst = str.c_str();
							myMessageHandler(ssst, QtWarningMsg);
							for (int j = 0; j < pins.count(); j++)
							{

								auto pn = pins[j];
								if (pn != p1)
								{

									p1->chain = nullptr;
									pins.removeOne(p1);
									new AddWhireCommand(p1->command, pn->command);
									new WhireRemoveComand(whires[i]);
									break;
								}
							}
						}
					}
				}
			}
			else
			{
				for (int j = 0; j < whires.count(); j++)
				{
					whires[j]->p1->chain = nullptr;
					whires[j]->p2->chain = nullptr;
					new WhireRemoveComand(whires[j]);
				}
				pins[0]->chain = nullptr;
				pins[0]->getpinWhire()->ClearInside();
				pins.removeOne(pins[0]);
				if (pins.isEmpty())
				{
					delete(this);
				}
			}
			p->pinWhire(false);
		}
	}
	catch (_exception ex)
	{

	}

	myMessageHandler( "ChainRemPin");
}

void Chain::moveToChain(Chain* chain)
{

	myMessageHandler("ChainmoveToChainHead",QtWarningMsg);
	auto pinss = chain->pins;

	for (int i = 0; i < pinss.size()-1; i++)
	{
		pinss[i]->RemoveFromChain();
	}
	for (int i = 0; i < pinss.size(); i++)
	{
		new AddWhireCommand(pins[0]->command, pinss[i]->command);
	}
	myMessageHandler( "ChainmoveToChain");
}

void Chain::Dots()
{
	Pin* min, *max;
	min = pins[0];
	max = pins[0];
	foreach(auto p, pins)
	{
		p->dot()->setBig(true);
		if (p->y() < min->y())
		{
			min = p;
		}
		else if (p->y() > max->y())
		{
			max = p;
		}
	}

	min->dot()->setBig(false);
	max->dot()->setBig(false);
	myMessageHandler( "Dots");
}

