#pragma once
#ifndef ADDPINCOMAND_H
#define ADDPINCOMAND_H
#include <QUndoCommand>
class Port;
class Pin;
class AddComand;
class AddPinComand  : public QUndoCommand
{
public:
	AddPinComand(Port*p,QString name="");
	~AddPinComand();
	void undo() override;
	void redo() override;
	QString name = "";
	Pin* pn = nullptr;
	AddComand* prt;
};
#endif
