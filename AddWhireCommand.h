#pragma once

#include <QUndoCommand>
class Pin;
class Whire;
#include "pin.h"
class AddPinComand;
#include"AddPinComand.h"
#include"mygraphicsscene.h"
class AddWhireCommand  : public QUndoCommand
{
public:
	AddWhireCommand(AddPinComand* p11, AddPinComand* p22);
	~AddWhireCommand();
	void undo() override;
	void redo() override;
	AddPinComand* p1, *p2;
	Whire* whire;
};
