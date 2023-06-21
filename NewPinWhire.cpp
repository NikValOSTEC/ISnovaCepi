#include "NewPinWhire.h"
#include"pin.h"
#include"Dot.h"
#include"chain.h"
NewPinWhire::NewPinWhire(Pin* p, QThread* th)
	: CustomColliderLineRecoursive(false,p->dot(),p->coredot())
{
	p->coredot()->setColor(Qt::red);
	p->coredot()->setTriangle(true);
	p->coredot()->setPin(p);
	pin = p;
}

NewPinWhire::~NewPinWhire()
{

}

QColor NewPinWhire::color()
{
	if(pin->chain)
		return pin->chain->color;
	return QColor(Qt::black);
}
