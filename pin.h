#ifndef PIN_H
#define PIN_H

#include"ui_pin.h"
#include<qlineedit.h>

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
    void Update();
signals:
    void updSignal();
public:
    void EmitUpd(bool dotold=false);
    NewPinWhire* getpinWhire();
    Port* parCon;
    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void dragEnterEvent(QDragEnterEvent* event) override;
    virtual void dropEvent(QDropEvent* event) override;
    virtual void dragMoveEvent(QDragMoveEvent* event) override;
    virtual Dot* dot(bool recalc=false);
    virtual void dot(Dot* d);
    Dot* coredot();

    qreal x();
    qreal y();
    void pinWhire(bool show=true);
    void PinWUpd();
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
