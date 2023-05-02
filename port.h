#ifndef PORT_H
#define PORT_H

#include"portparent.h"

namespace Ui {
class Port;
}

class Port : public PortParent,QOpenGLWidget
{
    Q_OBJECT

public:
    explicit Port(AddComand* com, QWidget *parent = nullptr);
    virtual ~Port();
    AddComand* adcom;
    void Remove() override;
    Pin* addPin(QString name = "", int index = -1) override;
    void showContextMenu(const QPoint& pos);
    virtual Pin* addPinSl(QString name="");
    virtual void RemoveSL();
    void Update(bool updF=false);
    ProxyRectPort* proxy();
    void proxy(ProxyRectPort*prox);
    void setFilter();


protected:
    Ui::Port *ui;
    virtual QMenu* ContextMenu();
    ProxyRectPort* _proxy;
};

#endif // PORT_H
