#include "GView.h"
#include "proxyrectport.h"
#include <QOpenGLPaintDevice>
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

    ((ProxyRectPort*)item)->ColiderCheck(false);
    QGraphicsView::mousePressEvent(event);

}

GView::~GView()
{}
