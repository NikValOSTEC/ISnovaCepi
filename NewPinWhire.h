#pragma once
#ifndef NEWPINWHIRE_H
#define NEWPINWHIRE_H
#include<qthread.h>
#include<qobject.h>
class CustomColliderLineRecoursive;
#include"CustomColliderLineRecoursive.h"
class Pin;
class NewPinWhire  : public CustomColliderLineRecoursive
{
	Q_OBJECT
public:
	NewPinWhire(Pin* p, QThread* th);
	~NewPinWhire();

	QColor color() override;
private:
	Pin* pin;
};
#endif
