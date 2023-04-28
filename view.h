#ifndef VIEW_H
#define VIEW_H
#include<QFrame>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGridLayout>
#include<QEvent>
#include <QGraphicsView>
#include<QWheelEvent>
#include<QSlider>
#include<QMouseEvent>
#include<QLineEdit>
#include<QScrollBar>
#include<QGraphicsItem>
#include<QMenu>
#include <qundostack.h>
#include<qmath.h>
#include<QWheelEvent>
#include<QSlider>
#include<QMouseEvent>
#include<QDebug>
class MYGraphicsScene;
#include"mygraphicsscene.h"
#include<qevent.h>
class GView;
#include "GView.h"

class View : public QFrame
{
    Q_OBJECT
public:
    View();
    MYGraphicsScene* GScene();
    void GScene(MYGraphicsScene* scene);
    QColor backGroundColor();
    void backGroundColor(QColor color);
    GView* view();
    QUndoStack* stack;

protected:
    GView* graphicsview;
    int _scale;
    virtual QMenu* ContextMenu();
protected slots:
    virtual void showContextMenu(const QPoint& pos);
signals:
    void SceneChanged();
public slots:
    void stckUndo();
    void stckRedo();
    void AdddPort();
    void AdddPort(int x, int y, QString name);

public:
    void stackPush(QUndoCommand* com)
    {
        stack->push(com);
    }
#if QT_CONFIG(wheelevent)
        void wheelEvent(QWheelEvent* e); 
#endif
};

#endif // VIEW_H
