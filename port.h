#ifndef PORT_H
#define PORT_H

#include <QWidget>
class Pin;
#include "pin.h"
class ProxyRectPort;
#include"proxyrectport.h"
#include"AddPinComand.h"
class AddComand;
#include "AddComand.h"
#include <QOpenGLWidget>

namespace Ui {
class Port;
}

class Port : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit Port(AddComand* com, QWidget *parent = nullptr);
    ~Port();
    QString name();
    void name(QString str);
    static QVector<Port*> portsVector;
    QVector<Pin*>pins();
    Pin* addPin(QString name = "", int index = -1);
    AddComand* adcom;
    void Remove();
private slots:
    void on_pushButton_clicked();
public slots:
    void showContextMenu(const QPoint& pos);
    Pin* addPinSl(QString name="");
    void RemoveSL();
    void Update(bool updF=false);
    ProxyRectPort* proxy();
    void proxy(ProxyRectPort*prox);
    void setFilter();


private:
    Ui::Port *ui;
protected:
    virtual QMenu* ContextMenu();
    ProxyRectPort* _proxy;
};

#endif // PORT_H
