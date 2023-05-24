#ifndef PORT_H
#define PORT_H

#include"ui_port.h"
#include"qobject.h"
class AddComand;
#include"AddComand.h"
class ProxyRectPort;
#include"proxyrectport.h"
namespace Ui {
class Port;
}

class Port : public QWidget
{
    Q_OBJECT

public:
    explicit Port(AddComand* com, QWidget *parent = nullptr);
    Port();
    virtual ~Port();

    QString name();
    void name(QString str);
    static QVector<Port*> portsVector;
    QVector<Pin*>pins();
    AddComand* adcom;
    void Remove();
private slots:
    void on_pushButton_clicked();
public slots:
    virtual Pin* addPin(QString name = "", int index = -1);
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
