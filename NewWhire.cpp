#include "NewWhire.h"
#include"pin.h"
#include"chain.h"
#include"Dot.h"
#include"AddWhireCommand.h"
#include"port.h"
#include"proxyrectport.h"
NewWhire::NewWhire(Pin* pp1, Pin* pp2, AddWhireCommand* comm):
	CustomColliderLineRecoursive(true,pp1->dot(), pp2->dot())
{
    pp1->dot()->whires.append(this);
    pp2->dot()->whires.append(this);
	p1 = pp1;
	p2 = pp2;
    this->command = comm;

    if (p1->chain == nullptr && p2->chain == nullptr)
    {
        chain = new Chain();
        int x = (p1->coredot()->pos().x() + p2->coredot()->pos().x()) / 2;
        int y = (p1->coredot()->pos().y() + p2->coredot()->pos().y()) / 2;
        p1->dot()->setX(x);
        p2->dot()->setX(x);
    }
    else if (p1->chain == p2->chain)
    {
        return;
    }
    else if (p2->chain != nullptr && p1->chain != nullptr)
    {
        p1->chain->moveToChain(p2->chain);
        chain = p1->chain;
        p2->dot()->setPos(p1->dot()->pos());
    }
    else if (p1->chain != nullptr)
    {
        chain = p1->chain;
        p2->dot()->setPos(p1->dot()->pos());
    }
    else if (p2->chain != nullptr)
    {
        chain = p2->chain;
        p1->dot()->setPos(p2->dot()->pos());
    }
    p1->parCon->graphicsProxyWidget()->scene()->addItem(this);
    chain->AddPin(p1);
    chain->AddPin(p2);

}

NewWhire::~NewWhire()
{

    p1->dot()->whires.removeOne(this);
    p2->dot()->whires.removeOne(this);
}

void NewWhire::AddComandW(Pin *p1, Pin *p2)
{
    new AddWhireCommand(p1->command,p2->command);
}

QColor NewWhire::color()
{
    return chain->color;
}


