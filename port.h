#pragma once
#ifndef PORT_H
#define PORT_H
#include"ui_port.h"
#include"qobject.h"
#include<QMenu>
#include<qwidget.h>
class AddComand;
class Pin;
class ProxyRectPort;
namespace Ui {
class Port;
}

class Port : public QWidget
{
    Q_OBJECT

public:
    qreal x();
    qreal y();
    explicit Port(AddComand* com, QWidget *parent = nullptr);
    Port();
    virtual ~Port();

    QString name();
    void name(QString str);
    static QVector<Port*> portsVector;
    QVector<Pin*>pins();
    AddComand* adcom;
    void Remove();
    virtual Pin* addPin(QString name = "", int index = -1);

private slots:
    void showContextMenu(const QPoint& pos);
    void on_pushButton_clicked();
    Pin* addPinSl(QString name="");
    void RemoveSL();
public slots:
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
