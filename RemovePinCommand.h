#pragma once
#ifndef REMOVEPINCOMMAND_H
#define REMOVEPINCOMMAND_H
#include<QUndoCommand>
class Pin;
class Port;
class AddPinComand;
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
#endif
