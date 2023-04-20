#include "chaintable.h"
#include"port.h"
#include"QHeaderView.h"
#include"QInputDialog.h"

ChainTable::ChainTable()
	: QTableWidget()
{
	m_connection= connect(this, SIGNAL(cellChanged(int, int)),
this, SLOT(CellChange(int, int)));
	connect(this, SIGNAL(cellClicked(int, int)),
	this, SLOT(CellClck(int, int)));

	auto header = this->horizontalHeader();
	connect(header, &QHeaderView::sectionClicked, [this](int logicalIndex) {
		QString text = this->horizontalHeaderItem(logicalIndex)->text();
		bool ok;
		QString ntext = QInputDialog::getText(0, "New Name",
			"Name", QLineEdit::Normal,
			text, &ok);
		if (ok)
		{
			this->horizontalHeaderItem(logicalIndex)->setText(ntext);
			Port::portsVector[logicalIndex]->name(ntext);
		}
		
	});
}


void ChainTable::UpdateTable()
{
	disconnect(m_connection);
	auto connectors = Port::portsVector;
	auto chains = Chain::chains;
	QList<QString>HeadersVertical;
	QList<QString>HeadersHorizontal;
	HeadersVertical = QList<QString>();
	for (int i = 0; i < chains.size()-1; i++)
	{
		if (chains[i]->pins.size() < 2)
		{
			delete chains[i];
			chains.remove(i);
		}
	}
	for (int i = 0; i < chains.size(); i++)
	{
		HeadersVertical.append(QString::number(i+1));
	}
	for (int i = 0; i < connectors.size(); i++)
	{
		HeadersHorizontal.append(connectors[i]->name());
	}

	setRowCount(chains.size()+1);
	if (connectors.size() < 2)
		setColumnCount(2);
	else
		setColumnCount(connectors.size());
	setHorizontalHeaderLabels(HeadersHorizontal);
	setVerticalHeaderLabels(HeadersVertical);
	QVector<QVector<QString>>vals = QVector<QVector<QString>>();
	for (int i = 0; i < chains.size(); i++)
	{
		vals.append(QVector<QString>());
		for (int j = 0; j < connectors.size(); j++)
		{
			vals.last().append(QString(""));
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
		for (int j = 0; j < connectors.size(); j++)
		{
			this->setItem(i, j, new QTableWidgetItem(vals[i][j]+";"));
		}
	}
	this->setItem(chains.size(), 0, new QTableWidgetItem("+"));
	this->setItem(chains.size(), 1, new QTableWidgetItem("+"));
	m_connection= connect(this, SIGNAL(cellChanged(int, int)),
this, SLOT(CellChange(int, int)));
	
}

ChainTable::~ChainTable()
{

}

void ChainTable::AddPort()
{
	QPointF pos;
	if (Port::portsVector.count() < 1)
		pos = QPointF(0, 0);
	else
		pos = Port::portsVector.last()->pos();
	pos.setX(pos.x() + 300);
	pos.setY(pos.y() + 300);
	if (view == nullptr)
	{
		return;
	}
	view->AddPort(pos.x(), pos.y(), "");
	UpdateTable();
}

void ChainTable::AddChain()
{
	new Chain();
	UpdateTable();
}

void ChainTable::CellChange(int row, int column)
{
	auto chainW=Chain::chains[row];
	for (int i = 0; i < chainW->pins.size(); i++)
	{
		auto clm = (Port::portsVector.indexOf(chainW->pins[i]->parCon));
		if (clm == column)
		{
			if (!(item(row, column)->text().contains(";" + chainW->pins[i]->name() + ";")))
			{
				chainW->pins[i]->RemoveFromChain();
			}
		}
	}
	auto str = item(row, column)->text();
	auto spl = str.split(";");
	if (!Chain::chains.contains(chainW))
	{
		chainW = new Chain();
	}
	QVector<Pin*>pins = QVector<Pin*>();
	QVector<Pin*>addPin = QVector<Pin*>();
	for (int i = 0; i < Port::portsVector.size(); i++)
	{
		auto str=this->item(row, i)->text();
		auto splt = str.split(";");
		splt.remove(0);
		splt.remove(splt.count() - 1);
		auto portpns = Port::portsVector[i]->pins();
		foreach (auto spp, splt)
		{
			auto found=std::find_if(
				portpns.begin(), portpns.end(),
				[&spp](auto x) { return x->name() == spp;  });
			if ((found) == portpns.end())
			{
				auto pn=Port::portsVector[i]->addPin(spp);
				addPin.append(pn);
				pins.append(pn);

			}
			else
			{
				if (!chainW->pins.contains(*found))
				{
					addPin.append(*found);
				}

				pins.append(*found);
			}

		}


	}
	if (pins.count() > 2)
	{
		for (int i = 0; i < addPin.count(); i++)
		{
			if (addPin[i]->chain == chainW)
			{
			}
			else if (addPin[i]->chain != nullptr)
			{
				addPin[i]->RemoveFromChain();
				if (pins[0] != addPin[i])
					new Whire(addPin[i], pins[0]);
				else
					new Whire(addPin[i], pins[1]);
			}
			else
			{
				if (pins[0] != addPin[i])
					new Whire(addPin[i], pins[0]);
				else
					new Whire(addPin[i], pins[1]);

			}
		}
	}
}

void ChainTable::CellClck(int row, int colum)
{
	if ((row == this->rowCount() - 1) && (colum == 1))
	{
		AddPort();
	}
	else if ((row == this->rowCount() - 1) && (colum == 0))
	{
		AddChain();
	}
}

