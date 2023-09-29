#pragma once
#ifndef PORT_H
#define PORT_H
#include"ui_port.h"
#include"qobject.h"
#include<QMenu>
#include <QSpacerItem>
#include<qwidget.h>
class AddComand;
class Pin;
class ProxyRectPort;
namespace Ui {
class Port;
}

/// <summary>
/// ������ �� �����
/// <para>
/// ������������ � ������ 
/// </para>
/// </summary>
class Port : public QWidget
{
    Q_OBJECT

public:
    /// <summary>
    /// ���������� x �� �����
    /// </summary>
    /// <returns></returns>
    qreal x();
    /// <summary>
    /// ���������� y �� �����
    /// </summary>
    /// <returns></returns>
    qreal y();
    /// <summary>
    /// ������� ������ 
    /// </summary>
    /// <param name="com">Undo ������� � ������� ������������ ������</param>
    /// <param name="parent"></param>
    explicit Port(AddComand* com, QWidget *parent = nullptr);
    /// <summary>
    /// ������� ������
    /// </summary>
    Port();
    /// <summary>
    /// ����������
    /// </summary>
    virtual ~Port();
    /// <summary>
    /// ��� �������
    /// </summary>
    /// <returns></returns>
    QString name();
    /// <summary>
    /// ��������� ����� �������
    /// </summary>
    /// <param name="str"></param>
    void name(QString str);
    /// <summary>
    /// ����������� ������ ��� ������� �� ���� �������� �� ���
    /// </summary>
    static QVector<Port*> portsVector;
    /// <summary>
    /// ������ ���� ��������� �������
    /// </summary>
    /// <returns></returns>
    QVector<Pin*>pins();
    /// <summary>
    /// ������� Undo �� ������� ������ ������ ������
    /// </summary>
    AddComand* adcom;
    /// <summary>
    /// �������� �������
    /// </summary>
    void Remove();
    /// <summary>
    /// ���������� ������ ��������
    /// </summary>
    /// <param name="name">��� ������ ��������</param>
    /// <param name="index">����� � ������ ��������� � �������</param>
    /// <param name="bl">������������ � ������ �� ���������</param>
    /// <returns>��������� �������</returns>
    virtual Pin* addPin(QString name = "", int index = -1,bool bl=true);

private slots:
    /// <summary>
    /// ������������ ������������ ����
    /// </summary>
    void showContextMenu(const QPoint& pos);
    void on_pushButton_clicked();
    /// <summary>
    /// ���� �� ��������
    /// </summary>
    void RemoveSL();
public slots:
    /// <summary>
    /// ���������� �������� ����
    /// </summary>
    /// <param name="name">��� ������ ��������</param>
    /// <returns>��������� �������</returns>
    Pin* addPinSl(QString name = "");
    /// <summary>
    /// �������� ������� � ��������
    /// </summary>
    void Update(bool updF=false);
    /// <summary>
    /// ������ � ������� ������ ������
    /// </summary>
    /// <returns></returns>
    ProxyRectPort* proxy();
    /// <summary>
    /// �������� ������ � ������� ������������ ������
    /// </summary>
    /// <param name="prox"></param>
    void proxy(ProxyRectPort*prox);


protected:
    Ui::Port *ui;
    /// <summary>
    /// ����������� ����. ��������; ���������� ��������...
    /// </summary>
    /// <returns></returns>
    virtual QMenu* ContextMenu();
    /// <summary>
    /// ������ � ������� ������ ������
    /// </summary>
    ProxyRectPort* _proxy;
    /// <summary>
    /// �������� ��� ������������ ���������
    /// </summary>
    QSpacerItem* spacer;
};

#endif // PORT_H
