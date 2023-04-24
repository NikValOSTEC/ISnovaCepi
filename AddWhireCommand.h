#pragma once

#include <QUndoCommand>
#include "pin.h"
#include"mygraphicsscene.h"
class AddWhireCommand  : public QUndoCommand
{
public:
	AddWhireCommand(Pin* p11, Pin* p22);
	~AddWhireCommand();
	void undo() override;
	void redo() override;
	Pin* p1, *p2;
	Whire* whire;
};
