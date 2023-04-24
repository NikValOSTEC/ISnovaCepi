#pragma once

#include <QUndoCommand>

class RemovePinCommand  : public QUndoCommand
{

public:
	RemovePinCommand();
	~RemovePinCommand();
	void undo() override;
	void redo() override;
};
