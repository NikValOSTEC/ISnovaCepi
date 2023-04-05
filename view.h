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
#include<qmath.h>
#include<QWheelEvent>
#include<QSlider>
#include<QMouseEvent>
#include<QDebug>
#include"mygraphicsscene.h"

class View : public QFrame
{
    Q_OBJECT
public:
    View();
    MYGraphicsScene* GScene();
    void GScene(MYGraphicsScene *scene);
    QColor backGroundColor();
    void backGroundColor(QColor color);
    QGraphicsView* view();

protected:
    QGraphicsView* graphicsview;
    int _scale;
    virtual QMenu* ContextMenu();
protected slots:
    virtual void showContextMenu(const QPoint& pos);
signals:
    void SceneChanged();
public slots:
    void AddPort();
};

#endif // VIEW_H
