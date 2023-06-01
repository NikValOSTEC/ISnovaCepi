#pragma once
#ifndef ADDWHIRECOMMAND_H
#define ADDWHIRECOMAND_H
#include<QUndoCommand>
class AddPinComand;
class NewWhire;
class AddWhireCommand: public QUndoCommand
{
public:
	AddWhireCommand(AddPinComand* p11, AddPinComand* p22);
	~AddWhireCommand();
	void undo() override;
	void redo() override;
	AddPinComand* p1, *p2;
	NewWhire* whire;
};
#endif
