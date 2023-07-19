#include "PortTemplate.h"
#include"port.h"
#include"PinTemplate.h"
#include"PortTwmplateObject.h"
#include"SaveTemplates.h"
#include"QLineEditFocusOutSignal.h"
PortTemplate::PortTemplate(PortTwmplateObject* o)
    : Port()
{
        object = o;
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

void PortTemplate::closeEvent(QCloseEvent* event)
{

    if (event->spontaneous()) {
        object->name->setText(object->templ->name());
        SaveTemplates::Save(object);
    }
    else {
        QWidget::closeEvent(event);
    }
}

QMenu* PortTemplate::ContextMenu()
{
    QMenu* myMenu = new QMenu();
    myMenu->addAction("addPin", this, SLOT(addPinSl()));
    return myMenu;
}


