#pragma once

class CustomColliderLineRecoursive;
#include "CustomColliderLineRecoursive.h"
class NewPinWhire  : public CustomColliderLineRecoursive
{
	Q_OBJECT
public:
	NewPinWhire(Pin* p, QThread* th);
	~NewPinWhire();
};
