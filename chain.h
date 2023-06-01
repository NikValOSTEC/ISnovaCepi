#pragma once
#include<qobject.h>
#include"qcolor.h"
class Pin;
#ifndef CHAIN_H
#define CHAIN_H
class Chain :public QObject
{
    Q_OBJECT
public:
    Chain();
    ~Chain();
    void AddPin(Pin* p);
    void RemovePin(Pin* p);
    static QVector<Chain*> chains;
    QVector<Pin*> pins;
    void moveToChain(Chain* chain); 
    void Dots();
    QColor color;
};
#endif
