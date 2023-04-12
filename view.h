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
class MYGraphicsScene;
#include"mygraphicsscene.h"

class View : public QGraphicsView
{
    Q_OBJECT
public:
    View();
    MYGraphicsScene* GScene();
    void GScene(MYGraphicsScene *scene);
    QColor backGroundColor();
    void backGroundColor(QColor color);

    void mouseMoveEvent(QMouseEvent* mouseEvent) override;
    void mouseReleaseEvent(QMouseEvent* mouseEvent) override;
protected:
    int _scale;
    virtual QMenu* ContextMenu();
protected slots:
    virtual void showContextMenu(const QPoint& pos);
signals:
    void SceneChanged();
public slots:
    void AddPort();
#if QT_CONFIG(wheelevent)
    void wheelEvent(QWheelEvent* e);
#endif
};

#endif // VIEW_H
