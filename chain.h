#ifndef CHAIN_H
#define CHAIN_H
#include<qvector.h>
#include"whire.h"
#include<QObject>
class Pin;
#include"pin.h"
#include<qobject.h>
#include"WhireRemoveComand.h"
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
    QColor color;
};

#endif // CHAIN_H
