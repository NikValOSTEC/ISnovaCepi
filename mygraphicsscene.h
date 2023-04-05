#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H

#include<QGraphicsScene>
class MYGraphicsScene : public QGraphicsScene
{
public:
    explicit MYGraphicsScene(QObject *parent = nullptr);
    void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent) override;
};

#endif // MYGRAPHICSSCENE_H
