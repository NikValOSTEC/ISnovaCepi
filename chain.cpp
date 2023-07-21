#include "chain.h"
#include"WhireRemoveComand.h"
#include"pin.h"
#include"AddWhireCommand.h"
#include"Dot.h"
#include"NewWhire.h"
#include"NewPinWhire.h"
Chain::Chain():QObject()
{
	pins = QVector<Pin*>();
	chains.append(this);
}

Chain::~Chain()
{
	chains.removeOne(this);
}

void Chain::AddPin(Pin* p)
{
	if (!pins.contains(p))
	{
		pins.append(p);
		p->chain = this;
	}
}

void Chain::RemovePin(Pin* p)
{
	try
	{
		if (pins.removeOne(p))
		{
			p->getpinWhire()->ClearInside();
			p->chain = nullptr;
			auto whires = p->dot()->whires;
			if (pins.count() > 1)
			{
				for (int i = 0; i < whires.count(); i++)
				{
					if (whires[i]->p1 == p)
					{
						if (whires[i]->p2->dot()->whires.count() > 1)
						{
							new WhireRemoveComand(whires[i]);
						}
						else
						{
							auto p2 = whires[i]->p2;
							for (int j = 0; j < pins.count(); j++)
							{
								auto pn = pins[j];
								if (pn != p2)
								{
									p2->chain = nullptr;
									pins.removeOne(p2);
									new WhireRemoveComand(whires[i]);
									new AddWhireCommand(pn->command, p2->command);
								}
							}
						}

					}
					else if (whires[i]->p2 == p)
					{
						if (whires[i]->p1->dot()->whires.count() > 1)
						{
							new WhireRemoveComand(whires[i]);
						}
						else
						{
							auto p1 = whires[i]->p1;
							for (int j = 0; j < pins.count(); j++)
							{

								auto pn = pins[j];
								if (pn != p1)
								{

									p1->chain = nullptr;
									pins.removeOne(p1);
									new WhireRemoveComand(whires[i]);
									new AddWhireCommand(p1->command, pn->command);
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
}

void Chain::moveToChain(Chain* chain)
{
	for (int i = 0; i > chain->pins.size(); i++)
	{
		chain->pins[i]->chain = this;
		this->pins.append(chain->pins[i]);
		chain->pins.remove(i);
		
	}
	delete chain;
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
}

