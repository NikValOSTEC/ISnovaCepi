#include "PortTwmplateObject.h"

void PortTwmplateObject::dragEnterEvent(QDragEnterEvent* event)
{
	if (event->mimeData()->hasFormat("PortTemp"))
	{
		event->accept();
	}
	else
		event->ignore();
}
void PortTwmplateObject::dropEvent(QDropEvent* event)
{
}
void PortTwmplateObject::dragMoveEvent(QDragMoveEvent* event)
{
	if (event->mimeData()->hasFormat("PortTemp"))
	{
		event->accept();
	}
	else
		event->ignore();
}
void PortTwmplateObject::mousePressEvent(QMouseEvent* event)
{
	QDrag* drag = new QDrag(this);
	QMimeData* mimeData = new QMimeData();
	uintptr_t adress = (uintptr_t)this;
	QString str = QString::number(adress);
	mimeData->setData("PortTemp", str.toUtf8());
	drag->setMimeData(mimeData);
	Qt::DropAction dropAction = drag->exec();
}
void PortTwmplateObject::delPush()
{
	delete this;
}

void PortTwmplateObject::namecheck(bool foc)
{
	if (!foc)
	{
		auto lst=this->parent()->children();
		foreach(auto obj, lst)
		{

		}
	}
}

void PortTwmplateObject::editPush()
{
	templ->show();
}
PortTwmplateObject::PortTwmplateObject()
{
	templ = new PortTemplate();
	this->editpb = new QPushButton(this);
	this->name = new QLineEditFocusOutSignal(this);
	this->delpb = new QPushButton(this);
	editpb->setText("edit");
	delpb->setText("del");
	this->setLayout(new QVBoxLayout());
	this->layout()->addWidget(name);
	this->layout()->addWidget(editpb);
	this->layout()->addWidget(delpb);
	
	connect(editpb, SIGNAL(clicked()), this, SLOT(editPush()));
	connect(delpb, SIGNAL(clicked()), this, SLOT(delPush()));
	connect(name, &QLineEditFocusOutSignal::focussed, this, &PortTwmplateObject::namecheck);
}

PortTwmplateObject::~PortTwmplateObject()
{
	delete templ;
}
