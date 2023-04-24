#pragma once

#include <QUndoCommand>

class AddPinComand  : public QUndoCommand
{
public:
	AddPinComand(QObject *parent);
	~AddPinComand();
	void undo() override;
	void redo() override;
};
