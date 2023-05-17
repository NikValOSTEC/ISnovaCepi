#include "NewWhire.h"

NewWhire::NewWhire(Pin* pp1, Pin* pp2, AddWhireCommand* comm):
	CustomColliderLineRecoursive(true,pp1->dot(), pp2->dot())
{
    pp1->dot()->whires.append(this);
    pp2->dot()->whires.append(this);
	p1 = pp1;
	p2 = pp2;
    this->command = comm;
    if (p1->chain == nullptr && p2->chain == nullptr)
        chain = new Chain();
    else if (p1->chain == p2->chain)
    {
        return;
    }
    else if (p2->chain != nullptr && p1->chain != nullptr)
    {
        p1->chain->moveToChain(p2->chain);
        chain = p1->chain;
    }
    else if (p1->chain != nullptr)
    {
        chain = p1->chain;
    }
    else if (p2->chain != nullptr)
    {
        chain = p2->chain;
    }
    p1->parCon->graphicsProxyWidget()->scene()->addItem(this);

}

NewWhire::~NewWhire()
{

    p1->dot()->whires.removeOne(this);
    p2->dot()->whires.removeOne(this);
}
