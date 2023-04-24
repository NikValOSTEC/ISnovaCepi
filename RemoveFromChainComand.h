#pragma once

#include <QUndoCommand>

class RemoveFromChainComand  : public QUndoCommand
{
public:
	RemoveFromChainComand(QObject *parent);
	~RemoveFromChainComand();
	void undo() override;
	void redo() override;
};
