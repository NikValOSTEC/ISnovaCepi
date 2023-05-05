#pragma once

#include <QTableWidget>
#include<qmetaobject.h>
#include"mygraphicsscene.h"

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
