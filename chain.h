#ifndef CHAIN_H
#define CHAIN_H
#include<qvector.h>
#include"whire.h"
class Pin;
#include<QObject>
#include"pin.h"
#include<qobject.h>
class Chain :public QObject
{
    Q_OBJECT
public:
    Chain();
    void AddPin(Pin* p);
    void RemovePin(Pin* p);
    static QVector<Chain*>* chains;
    QVector<Pin*> pins;
};

#endif // CHAIN_H
