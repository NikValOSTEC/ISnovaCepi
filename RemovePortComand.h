#pragma once
#ifndef REMOVECOMAND_H
#define REMOVECOMAND_H
#include<QUndoCommand>
class Port;
class AddComand;
class View;
class RemovePortComand  : public QUndoCommand
{
public:
	RemovePortComand(Port* p);
	~RemovePortComand();	
	void undo() override;
	void redo() override;
	QString name;
	AddComand* addcom;
	View* v;
	int xx, yy;
};
#endif
