#include<qobject.h>
class Pin;
#include"pin.h"
#include<qcolor.h>
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
