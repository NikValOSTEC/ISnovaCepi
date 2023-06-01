#pragma once
#ifndef ADDCOMAND_H
#define ADDCOMAND_H
#include <QUndoCommand>
#include<QDebug>
#include<qgraphicsproxywidget.h>
class View;
class Port;
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
#endif
