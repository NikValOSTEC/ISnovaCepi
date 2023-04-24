#pragma once

#include <QUndoCommand>
#include "port.h"

class RemovePortComand  : public QUndoCommand
{
public:
	RemovePortComand(Port* p);
	~RemovePortComand();	
	void undo() override;
	void redo() override;
	QString name;
};
