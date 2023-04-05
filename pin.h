#ifndef PIN_H
#define PIN_H

class Port;
#include"port.h"
#include<QLineEdit>
#include <QWidget>
class dot;
#include"dot.h"
class PinLineColision;
#include"pinlinecolision.h"

namespace Ui {
class Pin;
}

class Pin : public QLineEdit
{
    Q_OBJECT

public:
    explicit Pin(Port* port,QLineEdit *parent = nullptr);
    ~Pin();
    void Update();
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


private:
    Ui::Pin *ui;
    dot* d;
    PinLineColision* pinW;

};

#endif // PIN_H
