#pragma once
class CustomColliderLineRecoursive;
#include"CustomColliderLineRecoursive.h"
class Chain;
#include"chain.h"
class AddWhireCommand;
#include"AddWhireCommand.h";
class Pin;
#include"pin.h"

class NewWhire  : public CustomColliderLineRecoursive
{
	Q_OBJECT
private:
public:

	Pin* p1 = nullptr, * p2 = nullptr;
	Chain* chain = nullptr;
	NewWhire(Pin*pp1,Pin*pp2,AddWhireCommand* comm);
	~NewWhire();
	AddWhireCommand* command;
};
