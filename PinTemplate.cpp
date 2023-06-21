#include "PinTemplate.h"
#include"port.h"
PinTemplate::PinTemplate(Port* p)
	: Pin(p,false)
{

}

void PinTemplate::dragEnterEvent(QDragEnterEvent* event)
{
}

void PinTemplate::dropEvent(QDropEvent* event)
{
}

void PinTemplate::dragMoveEvent(QDragMoveEvent* event)
{
}


PinTemplate::~PinTemplate()
{}
