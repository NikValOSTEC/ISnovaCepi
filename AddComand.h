#pragma once
class View;
#include "view.h"
class Port;
#include "port.h"
#include <qgraphicsproxywidget.h>
#include <QUndoCommand>

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
