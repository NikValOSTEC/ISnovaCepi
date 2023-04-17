#include "chaintable.h"
#include"port.h"

ChainTable::ChainTable()
	: QTableWidget()
{
	
}


void ChainTable::UpdateTable()
{
	auto connectors = Port::portsVector;
	auto chains = Chain::chains;

	setRowCount(chains.size());
	setColumnCount(connectors.size());
	QVector<QVector<QString>>vals = QVector<QVector<QString>>();
	for (int i = 0; i < chains.size()+1; i++)
	{
		vals.append(QVector<QString>());
		for (int j = 0; j < connectors.size(); j++)
		{
			vals.last().append(QString());
		}
	}
	for (int i = 0; i < chains.size(); i++)
	{
		for (int j = 0; j < chains[i]->pins.count(); j++)
		{
			auto indexCon = connectors.indexOf(chains[i]->pins[j]->parCon);
			vals[i][indexCon] = vals[i][indexCon] + ";" + chains[i]->pins[j]->name();

		}
	}

	for (int i = 0; i < chains.size(); i++)
	{
		for (int j = 0; j < chains[i]->pins.count(); j++)
		{
			this->setItem(i, j, new QTableWidgetItem(vals[i][j]));
		}
	}

}

ChainTable::~ChainTable()
{

}
