#include "chain.h"

Chain::Chain():QObject()
{
	pins = QVector<Pin*>();
	//chains->append(this);
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
					delete(whires[i]);
				}
				else
				{
					auto p1 = whires[i]->p1;
					for(int i=0;i<pins.count();i++)
					{
						if (pins[i] != p1)
						{

							whires[i]->p1 = pins[i];
						}
					}
				}

			}
			else if(whires[i]->p2 == p)
			{
				if (whires[i]->p1->Dot()->whires.count() > 1)
				{
					delete(whires[i]);
				}
				else
				{
				auto p2 = whires[i]->p2;
					for (int i = 0; i < pins.count(); i++)
					{
						if (pins[i] != p2)
						{

							whires[i]->p2 = pins[i];
						}
					}
				}
			}
		}
	}
}
