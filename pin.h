#pragma once
#ifndef PIN_H
#define PIN_H
#include<QThread>
#include"ui_pin.h"
#include<qgraphicsproxywidget.h>
#include<QColorDialog>
#include<QLineEdit>
class Port;
class NewPinWhire;
class AddPinComand;
class Chain;
class Dot;
namespace Ui {
class Pin;
}
/// <summary>
/// �������
/// </summary>
class Pin : public QLineEdit
{
    Q_OBJECT

public:
    /// <summary>
    /// ������� �������
    /// </summary>
    /// <param name="port">������ � ������� ��������� �������</param>
    /// <param name="bl">������ �� ������ � ��������</param>
    /// <param name="parent"></param>
    explicit Pin(Port* port,bool bl=true,QLineEdit *parent = nullptr);
    /// <summary>
    /// ����������
    /// </summary>
    ~Pin();
    /// <summary>
    /// ��������� �������� �� ������ � �������
    /// </summary>
    /// <returns></returns>
    int index();
    /// <summary>
    /// ��� ��������
    /// </summary>
    /// <returns></returns>
    const QString name();
    /// <summary>
    /// ��������� ����� ��������
    /// </summary>
    /// <param name="name"></param>
    void name(QString name);
public slots:
    /// <summary>
    /// ����������
    /// </summary>
    void Update(bool dotupd);
signals:
    /// <summary>
    /// ������ ����������
    /// </summary>
    void updSignal(bool upddots);
public:
    /// <summary>
    /// ����� ������� ����������
    /// </summary>
    /// <param name="dotold"></param>
    void EmitUpd(bool dotold=false);
    /// <summary>
    /// ���������� ������ �� ������� ��������
    /// </summary>
    /// <returns></returns>
    NewPinWhire* getpinWhire();
    /// <summary>
    /// ������ � ������� ����� �������
    /// </summary>
    Port* parCon;
    /// <summary>
    /// ������� ����� ������� ��������
    /// </summary>
    /// <param name="recalc">������������� �� ������ (��������)</param>
    /// <returns>������� ����� ����</returns>
    virtual Dot* dot(bool recalc = false);
    /// <summary>
    /// ��������� ������� ����� �������
    /// </summary>
    /// <param name="d"></param>
    virtual void dot(Dot* d);
private:
    /// <summary>
    /// ����������
    /// </summary>
    /// <param name="event"></param>
    void mousePressEvent(QMouseEvent* event) override;
    /// <summary>
    /// ����������
    /// </summary>
    virtual void dragEnterEvent(QDragEnterEvent* event) override;
    /// <summary>
    /// ����������
    /// </summary>
    virtual void dropEvent(QDropEvent* event) override;
    /// <summary>
    /// ����������
    /// </summary>
    virtual void dragMoveEvent(QDragMoveEvent* event) override;
public:
    /// <summary>
    /// ���������� ����� ������� �������
    /// </summary>
    /// <returns></returns>
    Dot* coredot();
    /// <summary>
    /// ���������� x �������� �� �����
    /// </summary>
    /// <returns></returns>
    qreal x();
    /// <summary>
    /// ���������� y �������� �� �����
    /// </summary>
    qreal y();
    /// <summary>
    /// ����������� ������� ��������
    /// </summary>
    /// <param name="show"></param>
    void pinWhire(bool show=true);
    /// <summary>
    /// �������� ������������ ��������� ����� �������
    /// </summary>
    /// <param name="upd"></param>
    void PinWUpd(bool upd = true);
    /// <summary>
    /// ���� � ������� ����������� �������
    /// </summary>
    Chain* chain;
    /// <summary>
    /// ������� ���������� �������� Undo
    /// </summary>
    AddPinComand* command=nullptr;
protected:
    /// <summary>
    /// ����������� ���� ��� ��������... �� ������ ������ ����
    /// </summary>
    /// <returns></returns>
    virtual QMenu* ContextMenu();
    Ui::Pin *ui;
    /// <summary>
    /// ���������� ��� ��������
    /// </summary>
    bool upd = false; 
public slots:
    /// <summary>
    /// �������� �� ����
    /// </summary>
    void RemoveFromChain();
    /// <summary>
    /// ��������
    /// </summary>
    void Remove();
protected slots:
    /// <summary>
    /// ������������ ������������ ����
    /// </summary>
    virtual void showContextMenu(const QPoint& pos);
    /// <summary>
    /// ����� colorDialog ��� ����� ����� ���� � ������� ������ �������
    /// </summary>
    void ChangeColor();
private:
    bool updaterbl;
    /// <summary>
    /// ������� ����� ������� �� ��������
    /// </summary>
    Dot* d;
    /// <summary>
    /// ���������� ����� ������� �� ��������
    /// </summary>
    Dot* cored;
    /// <summary>
    /// ������ �� ��������
    /// </summary>
    NewPinWhire* pinW;
    /// <summary>
    /// ����� � ������� ����� �������
    /// </summary>
    QThread* thread;
    /// <summary>
    /// ��� ��������
    /// </summary>
    QString _name;

};

#endif // PIN_H
