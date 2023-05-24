#pragma once
#include <QUndoCommand>
class View;
#include"view.h"
class Port;
#include"port.h"

class AddComand  : public QUndoCommand
{
public:
	AddComand(View* v, int x, int y,QString name="");
	~AddComand();
	void undo() override;
	void redo() override;
	Port* p;
	int xx, yy;
	View* v;
	QString name;
};
