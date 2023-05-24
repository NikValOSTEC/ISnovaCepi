#pragma once

#include<QUndoCommand>
class NewWhire;
#include"NewWhire.h"
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
