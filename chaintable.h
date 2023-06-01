#pragma once
#ifndef CHAINTABLE_H
#define CHAINTABLE_H
class View;
#include<qobject.h>
#include<qtablewidget.h>
#include<qinputdialog.h>
#include"qheaderview.h"

class ChainTable  : public QTableWidget
{
	Q_OBJECT

public:
	ChainTable();
	~ChainTable();
	View* view=nullptr;
	void AdddPortSL();
	void AddChain();
public slots:
	void UpdateTable();
	void CellChange(int row, int column);
	void CellClck(int row, int colum);
protected:
	QMetaObject::Connection m_connection;
};
#endif
