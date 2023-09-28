#include "NewPinWhire.h"
#include"pin.h"
#include"Dot.h"
#include"chain.h"
#include "MessageHandler.h"
NewPinWhire::NewPinWhire(Pin* p, QThread* th)
	: CustomColliderLineRecoursive(false,p->dot(),p->coredot())
{
	p->coredot()->setColor(Qt::red);
	p->coredot()->setTriangle(true);
	p->coredot()->setPin(p);
	pin = p;

	myMessageHandler( "NewPinWhire");
}

NewPinWhire::~NewPinWhire()
{
	myMessageHandler( "~NewPinWhire");
	
}

bool NewPinWhire::hasConection()
{
	return (isVisible() || (inside.count() > 0));
}


void NewPinWhire::ClearInside()
{

	prepareGeometryChange();
	foreach(auto vr, this->inside)
	{
		if (dynamic_cast<CustomColliderLineRecoursive*>(vr))
		{
			delete vr;
		}
	}
	inside.clear();
	if (pin->chain != nullptr)
		pin->pinWhire();
	else
		pin->pinWhire(false);
	lastcolide = nullptr;
	itsmine.clear();
	if (Vertical_f_Horizontal_t)
	{

		d1->Hdot = this;
		d2->Hdot = this;
		QObject::connect(d1, SIGNAL(moving(Dot*)), d2, SLOT(HorizontalDot(Dot*)));
		QObject::connect(d2, SIGNAL(moving(Dot*)), d1, SLOT(HorizontalDot(Dot*)));
	}
	else
	{

		d1->Vdot = this;
		d2->Vdot = this;
		QObject::connect(d1, SIGNAL(moving(Dot*)), d2, SLOT(VerticalDot(Dot*)));
		QObject::connect(d2, SIGNAL(moving(Dot*)), d1, SLOT(VerticalDot(Dot*)));
	}
	myMessageHandler( "NewPinWhireClearInside");
}

QColor NewPinWhire::color()
{
	if(pin->chain)
		return pin->chain->color;
	return QColor(Qt::black);
}
