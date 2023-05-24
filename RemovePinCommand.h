#pragma once
class Port;
class AddPinComand;
#include"port.h";
#include"AddPinComand.h"
class RemovePinCommand  : public QUndoCommand
{

public:
	RemovePinCommand(Pin*p);
	~RemovePinCommand();
	void undo() override;
	void redo() override;
	int pos = 0;
	QString name = "";
	AddPinComand* pinc;
	Port* prt;
	Pin* pin;

};
