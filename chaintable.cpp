#include "chaintable.h"
#include"port.h"
#include"chain.h"
#include"view.h"
#include"pin.h"
#include"NewWhire.h"
#include "MessageHandler.h"
ChainTable::ChainTable()
	: QTableWidget()
{
	m_connection= connect(this, SIGNAL(cellChanged(int, int)),
this, SLOT(CellChange(int, int)));
	connect(this, SIGNAL(cellClicked(int, int)),
	this, SLOT(CellClck(int, int)));

	auto header = this->horizontalHeader();
	connect(header, &QHeaderView::sectionClicked, [this](int logicalIndex) {
		if (logicalIndex > 0)
		{
			QString text = this->horizontalHeaderItem(logicalIndex)->text();
			bool ok;
			QString ntext = QInputDialog::getText(0, "New Name",
				"Name", QLineEdit::Normal,
				text, &ok);
			if (ok)
			{
				this->horizontalHeaderItem(logicalIndex)->setText(ntext);
				Port::portsVector[logicalIndex - 1]->name(ntext);
			}
		}

	});
	myMessageHandler( "ChainTable");
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
	HeadersVertical.append(" ");
	HeadersVertical.append(" ");
	for (int i = 0; i < chains.size(); i++)
	{
		HeadersVertical.append(QString::number(i+1));
	}
	HeadersHorizontal.append(" ");
	for (int i = 0; i < connectors.size(); i++)
	{
		HeadersHorizontal.append(connectors[i]->name());
	}

	setRowCount(chains.size()+2);
	setColumnCount(connectors.size()+1);
	for (int i = 0; i < chains.size() + 2;i++)
	{
		QTableWidgetItem* itemss = new QTableWidgetItem("");
		itemss->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		setItem(i, 0, itemss);
	}
	for (int i = 0; i < connectors.size() + 1; i++)
	{
		QTableWidgetItem* itemss = new QTableWidgetItem("");
		itemss->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		setItem(0, i, itemss);
		itemss = new QTableWidgetItem("");
		itemss->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		setItem(1, i, itemss);
	}
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
			this->setItem(i+2, j+1, new QTableWidgetItem(vals[i][j]+";"));
		}
	}


	QWidget* pWidget = new QWidget();
	QPushButton* btn_edit = new QPushButton();
	btn_edit->setText("+ port");
	QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
	pLayout->addWidget(btn_edit);
	pLayout->setAlignment(Qt::AlignCenter);
	pLayout->setContentsMargins(0, 0, 0, 0);
	pWidget->setLayout(pLayout);
	this->setCellWidget(0, 0, pWidget);

	connect(btn_edit, SIGNAL(clicked()), this, SLOT(AdddPortSL()));


	QWidget* pcWidget = new QWidget();
	QPushButton* btnc_edit = new QPushButton();
	btnc_edit->setText("+ chain");
	QHBoxLayout* pcLayout = new QHBoxLayout(pcWidget);
	pcLayout->addWidget(btnc_edit);
	pcLayout->setAlignment(Qt::AlignCenter);
	pcLayout->setContentsMargins(0, 0, 0, 0);
	pcWidget->setLayout(pcLayout);
	this->setCellWidget(1, 0, pcWidget);

	connect(btnc_edit, SIGNAL(clicked()), this, SLOT(AddChain()));





	m_connection= connect(this, SIGNAL(cellChanged(int, int)),
this, SLOT(CellChange(int, int)));
	myMessageHandler( "ChainTableUpdate");
	
}

ChainTable::~ChainTable()
{
	myMessageHandler( "~ChainTable");
}

void ChainTable::AdddPortSL()
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
	view->AdddPortSL(pos.x(), pos.y(), "");
	UpdateTable();
	myMessageHandler( "ChainTableAddPortSL");
}

void ChainTable::AddChain()
{
	new Chain();
	UpdateTable();
	myMessageHandler( "ChainTableAddChain");
}

void ChainTable::CellChange(int row, int column)
{
	if (Chain::chains.size() > row - 2)
	{
		auto chainW = Chain::chains[row - 2];
		for (int i = 0; i < chainW->pins.size(); i++)
		{
			auto clm = (Port::portsVector.indexOf(chainW->pins[i]->parCon)) + 1;
			if (clm == column)
			{
				if (!(item(row, column)->text().contains(";" + chainW->pins[i]->name() + ";")))
				{
					chainW->pins[i]->RemoveFromChain();
				}
			}
		}
	}
	///*

	Chain* chainWt;
	QVector<Pin*>pins = QVector<Pin*>();
	QVector<Pin*>addPin = QVector<Pin*>();
	for (int i = 1; i < this->columnCount(); i++)
	{
		auto str = item(row, i)->text();
		auto spl = str.split(";");
		if (Chain::chains.size() <= row - 2)
		{
			chainWt = new Chain();
		}
		else
		{
			chainWt = Chain::chains[row - 2];
		}
		str = this->item(row, i)->text();
		auto splt = str.split(";");
		splt.removeAt(0);
		splt.removeAt(splt.count() - 1);
		auto portpns = Port::portsVector[i - 1]->pins();
		foreach(auto spp, splt)
		{
			auto found = std::find_if(
				portpns.begin(), portpns.end(),
				[&spp](auto x) { return x->name() == spp;  });
			if ((found) == portpns.end())
			{
				auto pn = Port::portsVector[i - 1]->addPinSl(spp);
				addPin.append(pn);
				pins.append(pn);

			}
			else
			{
				if (!chainWt->pins.contains(*found))
				{
					addPin.append(*found);
				}

				pins.append(*found);
			}

		}
	}

	if (pins.count() >= 2)
	{
		for (int i = 0; i < addPin.count(); i++)
		{
			if (addPin[i]->chain == chainWt)
			{
			}
			else if (addPin[i]->chain != nullptr)
			{
				addPin[i]->RemoveFromChain();
				if (pins[0] != addPin[i])
                    NewWhire::AddComandW(addPin[i], pins[0]);
				else
                    NewWhire::AddComandW(addPin[i], pins[1]);
			}
			else
			{
				if (pins[0] != addPin[i])
                    NewWhire::AddComandW(addPin[i], pins[0]);
				else
                    NewWhire::AddComandW(addPin[i], pins[1]);

			}
		}
	}
	//*/
	myMessageHandler( "ChainTableCellChange");
}

