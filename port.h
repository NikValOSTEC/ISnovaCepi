#ifndef PORT_H
#define PORT_H

#include <QWidget>
class Pin;
#include "pin.h"
class ProxyRectPort;
#include"proxyrectport.h"

namespace Ui {
class Port;
}

class Port : public QWidget
{
    Q_OBJECT

public:
    explicit Port(QWidget *parent = nullptr);
    ~Port();
    QString name();
    void name(QString str);
    static QVector<Port*> portsVector;
    QVector<Pin*>pins();

private slots:
    void on_pushButton_clicked();
public slots:
    void showContextMenu(const QPoint& pos);
    void addPin();
    void Remove();
    void Update();
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
