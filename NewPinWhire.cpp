#include "NewPinWhire.h"
#include"pin.h"
#include"Dot.h"
NewPinWhire::NewPinWhire(Pin* p, QThread* th)
	: CustomColliderLineRecoursive(false,p->dot(),p->coredot())
{
	p->coredot()->setColor(Qt::red);
	p->coredot()->setTriangle(true);
	p->coredot()->setPin(p);
}

NewPinWhire::~NewPinWhire()
{

}
