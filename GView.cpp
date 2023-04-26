#include "GView.h"
#include "proxyrectport.h"
#include "dot.h"

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
            ((dot*)items[i])->Uupdate();

        }
        else if (items[i]->type() == 101)
        {
            ((ProxyRectPort*)items[i])->Update();
        }
    }
    QGraphicsView::mouseMoveEvent(event);
}

void GView::mouseReleaseEvent(QMouseEvent* event)
{
    QList<QGraphicsItem*> items = GScene()->selectedItems();
    if (items.count() == lastselected)
    {
        GScene()->clearSelection();
        lastselected = 0;
    }
    else
    {
        lastselected = items.count();
    }
    for (int i = 0; i < items.count(); i++)
    {
        if (items[i]->type() == 100)
        {
            ((dot*)items[i])->Uupdate(true);

        }
        else if (items[i]->type() == 101)
        {
            ((ProxyRectPort*)items[i])->Update();
        }
    }

    QGraphicsView::mouseReleaseEvent(event);
}

GView::~GView()
{}
