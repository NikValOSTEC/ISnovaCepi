#pragma once
#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H
#include<QGraphicsScene>
#include"view.h"
class MYGraphicsScene : public QGraphicsScene
{
public:
    View* Mview;
    int _scale = 100;
    explicit MYGraphicsScene(QObject *parent = nullptr);
private:
    int lastselected = 0;
};

#endif // MYGRAPHICSSCENE_H
