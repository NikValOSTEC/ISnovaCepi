#include "mygraphicsscene.h"
#include "dot.h"
#include "proxyrectport.h"
#include "qcoreevent.h"
#include "qgraphicsitem.h"
#include "qgraphicssceneevent.h"

MYGraphicsScene::MYGraphicsScene(QObject *parent)
    : QGraphicsScene{parent}
{
}

void MYGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    QList<QGraphicsItem *> items = selectedItems();
    for(int i=0;i<items.count();i++)
    {
        if(items[i]->type()==100)
        {
            ((dot*)items[i])->Uupdate();

        }
        else if(items[i]->type()==101)
        {
            ((ProxyRectPort*)items[i])->Update();
        }
    }
    QGraphicsScene::mouseMoveEvent(event);
}

void MYGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    QList<QGraphicsItem*> items = selectedItems();
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

    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}
