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

class Pin : public QLineEdit
{
    Q_OBJECT

public:
    explicit Pin(Port* port,bool bl=true,QLineEdit *parent = nullptr);
    ~Pin();
    int index();
    const QString name();
    void name(QString name);
public slots:
    void Update(bool dotupd);
signals:
    void updSignal(bool upddots);
public:
    void EmitUpd(bool dotold=false);
    NewPinWhire* getpinWhire();
    Port* parCon;
    virtual Dot* dot(bool recalc = false);
    virtual void dot(Dot* d);
private:
    void mousePressEvent(QMouseEvent* event) override;
    virtual void dragEnterEvent(QDragEnterEvent* event) override;
    virtual void dropEvent(QDropEvent* event) override;
    virtual void dragMoveEvent(QDragMoveEvent* event) override;
public:
    Dot* coredot();

    qreal x();
    qreal y();
    void pinWhire(bool show=true);
    void PinWUpd(bool upd = true);
    Chain* chain;
    AddPinComand* command=nullptr;
protected:
    virtual QMenu* ContextMenu();
    Ui::Pin *ui;

    bool upd = false; 
public slots:
    void RemoveFromChain();
    void Remove();
protected slots:
    virtual void showContextMenu(const QPoint& pos);
    void ChangeColor();


private:
    bool updaterbl;
    Dot* d;
    Dot* cored;
    NewPinWhire* pinW;
    QThread* thread;
    QString _name;

};

#endif // PIN_H
