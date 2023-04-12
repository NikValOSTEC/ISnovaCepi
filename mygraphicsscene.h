#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H

#include<QGraphicsScene>
class View;
#include"view.h"
class MYGraphicsScene : public QGraphicsScene
{
public:
    View* Mview;
    int _scale = 100;
    explicit MYGraphicsScene(QObject *parent = nullptr);
    //void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent) override;
    //void mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent) override;

};

#endif // MYGRAPHICSSCENE_H
