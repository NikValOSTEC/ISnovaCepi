#pragma once

#include <QUndoCommand>
class AddWhireCommand;
#include"AddWhireCommand.h"
class AddPinComand;
#include"AddPinComand.h"
class WhireRemoveComand  : public QUndoCommand
{
public:
	WhireRemoveComand(NewWhire* w);
	~WhireRemoveComand();
	void undo() override;
	void redo() override;
	AddPinComand* p1, * p2;
	AddWhireCommand* wc;
};
