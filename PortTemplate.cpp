#include "PortTemplate.h"
PortTemplate::PortTemplate()
    : Port()
{
}

Pin* PortTemplate::addPinn(QString name, int index)
{
    auto pn = new PinTemplate(this);
    pn->name(name);
    ((QVBoxLayout*)(this->ui->PinsList->layout()))->insertWidget(index, pn);
    return pn;
    update();
}

Pin* PortTemplate::addPinSl(QString name)
{
	return addPinn();
    update();
}

void PortTemplate::RemoveSL()
{
    delete this;
}

PortTemplate::~PortTemplate()
{}

QMenu* PortTemplate::ContextMenu()
{
    QMenu* myMenu = new QMenu();
    myMenu->addAction("addPin", this, SLOT(addPinSl()));
    return myMenu;
}


