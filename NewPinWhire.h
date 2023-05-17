#pragma once

class CustomColliderLineRecoursive;
#include "CustomColliderLineRecoursive.h"
class NewPinWhire  : public CustomColliderLineRecoursive
{
public:
	NewPinWhire(Pin* p, QThread* th);
	~NewPinWhire();
};
