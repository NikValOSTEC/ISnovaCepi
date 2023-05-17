#include "NewPinWhire.h"

NewPinWhire::NewPinWhire(Pin* p, QThread* th)
	: CustomColliderLineRecoursive(true,p->dot(),p->coredot())
{

}

NewPinWhire::~NewPinWhire()
{}
