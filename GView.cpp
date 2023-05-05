#include "GView.h"
#include "proxyrectport.h"
#include <QOpenGLPaintDevice>
#include "dot.h"
#include"qmimedata.h"
#include "PortTwmplateObject.h"

GView::GView(QObject* parent) : QGraphicsView()
{
}

MYGraphicsScene* GView::GScene()
{
    return (MYGraphicsScene*)scene();
}

void GView::mouseMoveEvent(QMouseEvent* event)
{
    QList<QGraphicsItem*> items = GScene()->selectedItems();
    for (int i = 0; i < items.count(); i++)
    {

        if (items[i]->type() == 100)
        {
            ((dot*)items[i])->Uupdate(false);

        }
        else if (items[i]->type() == 101)
        {
            ((ProxyRectPort*)items[i])->Update(false);
        }
    }
    QGraphicsView::mouseMoveEvent(event);
}

void GView::mouseReleaseEvent(QMouseEvent* event)
{
    QList<QGraphicsItem*> items = GScene()->selectedItems();
    for (int i = 0; i < items.count(); i++)
    {
        if (items[i]->type() == 100)
        {
            ((dot*)items[i])->Uupdate(true);

        }
        else if (items[i]->type() == 101)
        {
            ((ProxyRectPort*)items[i])->Update(true);
        }
    }

    QGraphicsView::mouseReleaseEvent(event);    
    if (items.count() == lastselected || items.count() == 1)
    {
        GScene()->clearSelection();
        lastselected = 0;
    }
    else
    {
        lastselected = items.count();
    }
}

void GView::mousePressEvent(QMouseEvent* event)
{
    QGraphicsItem* item = GScene()->itemAt(mapToScene(event->pos()),QTransform());
    if(item)
        ((ProxyRectPort*)item)->ColiderCheck(false);
    QGraphicsView::mousePressEvent(event);

}

void GView::dropEvent(QDropEvent* event)
{
    if (event->mimeData()->hasFormat("PortTemp"))
    {
        QVariant var = QVariant::fromValue(QString::fromUtf8(event->mimeData()->data("PortTemp")));
        uintptr_t address = var.value<uintptr_t>();
        PortTwmplateObject* obj = (PortTwmplateObject*)address;
        if (obj)
        {
            auto comand = GScene()->Mview->AdddPort();
            foreach(auto pn, obj->templ->pins())
            {
                comand->p->addPin(pn->name());
            }
        }
    }
    else
    {
        QGraphicsView::dropEvent(event);
    }
}

void GView::dragEnterEvent(QDragEnterEvent* event)
{
    if (event->mimeData()->hasFormat("PortTemp"))
    {
        event->accept();
    }
    else
        QGraphicsView::dragEnterEvent(event);

}

void GView::dragMoveEvent(QDragMoveEvent* event)
{
    if (event->mimeData()->hasFormat("PortTemp"))
    {
        event->accept();
    }

    else
        QGraphicsView::dragMoveEvent(event);
}

GView::~GView()
{}
