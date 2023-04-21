#ifndef PIN_H
#define PIN_H

class Port;
#include<thread>
#include<QThread>
#include"port.h"
#include<QLineEdit>
#include <QWidget>
#include<QMenu>
class dot;
#include"dot.h"
class PinLineColision;
#include"pinlinecolision.h"
class Pin;
#include"chain.h"
#include<qstring.h>
#include <QColorDialog>

namespace Ui {
class Pin;
}

class Pin : public QLineEdit
{
    Q_OBJECT

public:
    explicit Pin(Port* port,QLineEdit *parent = nullptr);
    ~Pin();
    const QString name();
    void name(QString name);
public slots:
    void Update();
signals:
    void updSignal();
public:
    void EmitUpd();
    Port* parCon;
    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void dragEnterEvent(QDragEnterEvent* event) override;
    virtual void dropEvent(QDropEvent* event) override;
    virtual void dragMoveEvent(QDragMoveEvent* event) override;
    dot* Dot(bool recalc=false);
    dot* Dot(dot* d);
    qreal x();
    qreal y();
    void pinWhire(bool show=true);
    void PinWUpd();
    Chain* chain;
protected:
    virtual QMenu* ContextMenu();

public slots:
    void RemoveFromChain();
protected slots:
    virtual void showContextMenu(const QPoint& pos);
    void Remove();
    void ChangeColor();


private:
    bool updaterbl;
    Ui::Pin *ui;
    dot* d;
    PinLineColision* pinW;
    QThread* thread;
    QString _name;

};

#endif // PIN_H
