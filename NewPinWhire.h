#pragma once

class CustomColliderLineRecoursive;
#include"CustomColliderLineRecoursive.h"
#include<qobject.h>
class Pin;
#include"pin.h"
class NewPinWhire  : public CustomColliderLineRecoursive
{
	Q_OBJECT
public:
	NewPinWhire(Pin* p, QThread* th);
	~NewPinWhire();
};
