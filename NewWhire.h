#ifndef NEWWHIRE_H
#define NEWWHIRE_H
#pragma once
#include"CustomColliderLineRecoursive.h"
class Pin;
class AddWhireCommand;
class Chain;
class NewWhire  : public CustomColliderLineRecoursive
{
	//Q_OBJECT
public:

	Pin* p1 = nullptr, * p2 = nullptr;
	Chain* chain = nullptr;
	NewWhire(Pin*pp1,Pin*pp2,AddWhireCommand* comm);
	~NewWhire();
	AddWhireCommand* command;
    static void AddComandW(Pin* p1,Pin* p2);
	QColor color() override;
};
#endif
