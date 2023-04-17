#pragma once

#include <QTableWidget>

class ChainTable  : public QTableWidget
{
	Q_OBJECT

public:
	ChainTable();
	~ChainTable();
public slots:
	void UpdateTable();
};
