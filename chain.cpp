#include "chain.h"

Chain::Chain()
{
	if (chains.isEmpty())
		chains = QVector < Chain * > ();
	chains.append(this);
}

void Chain::AddPin(Pin* p)
{
	pins.append(p);
}

void Chain::RemovePin(Pin* p)
{
	pins.removeOne(p);
	auto whires = p->Dot()->whires;
	if (pins.count() > 1)
	{
		for (int i = 0; i < whires.count(); i++)
		{
			if (whires[i]->p1 == p)
			{
				if(whires[i]->p2->Dot()->whires.count()>0)
			}
			else if(whires[i]->p2 == p)
			{

			}
		}
	}
}
