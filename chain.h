#ifndef CHAIN_H
#define CHAIN_H
#include<qvector.h>
#include"whire.h"

class Chain
{
public:
    Chain();
    void AddPin(Pin* p);
    void RemovePin(Pin* p);
    static QVector<Chain*> chains;
    QVector<Pin*> pins;
};

#endif // CHAIN_H
