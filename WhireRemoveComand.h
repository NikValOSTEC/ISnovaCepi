#pragma once
#ifndef WHIREREMOVECOMAND_H
#define WHIREREMOVECOMAND_H
#include<QUndoCommand>
class NewWhire;
class AddPinComand;
class AddWhireCommand;
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
#endif
