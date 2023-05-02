
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

class PortParent : public QWidget
{
    Q_OBJECT

public:
    explicit PortParent();
    ~PortParent();
    QString name();
    void name(QString str);
    QVector<Pin*>pins();
    void Remove();
private slots:
    void on_pushButton_clicked();
public slots:
    virtual Pin* addPin(QString name = "", int index = -1);
    void showContextMenu(const QPoint& pos);
    virtual Pin* addPinSl(QString name = "");
    virtual void RemoveSL();
    void Update(bool updF = false);
    ProxyRectPort* proxy();
    void proxy(ProxyRectPort* prox);
    void setFilter();


protected:
    Ui::Port* ui;
    virtual QMenu* ContextMenu();
    ProxyRectPort* _proxy;
};
