#include "chain.h"

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
		pins.removeOne(p);
		p->chain = nullptr;
		auto whires = p->Dot()->whires;
		if (pins.count() > 1)
		{
			for (int i = 0; i < whires.count(); i++)
			{
				if (whires[i]->p1 == p)
				{
					if (whires[i]->p2->Dot()->whires.count() > 1)
					{
						new WhireRemoveComand(whires[i]);
					}
					else
					{
						auto p2 = whires[i]->p2;
						for (int j = 0; j < pins.count(); j++)
						{
							if (pins[j] != p2)
							{
								new WhireRemoveComand(whires[i]);
								auto pn = pins[j];
								pn->chain = nullptr;
								pins.removeOne(pn);
								new AddWhireCommand(p2->command, pn->command);
							}
						}
					}

				}
				else if (whires[i]->p2 == p)
				{
					if (whires[i]->p1->Dot()->whires.count() > 1)
					{
						new WhireRemoveComand(whires[i]);
					}
					else
					{
						auto p1 = whires[i]->p1;
						for (int j = 0; j < pins.count(); j++)
						{
							if (pins[j] != p1)
							{
								new WhireRemoveComand(whires[i]);
								auto pn = pins[j];
								pn->chain = nullptr;
								pins.removeOne(pn);
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
				new WhireRemoveComand(whires[j]);
			}
			p->pinWhire(false);
			pins[0]->pinWhire(false);
			pins[0]->chain = nullptr;
			pins.removeOne(pins[0]);
			if (pins.isEmpty())
			{
				delete(this);
			}
		}
		p->pinWhire(false);
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

