#ifndef VIEW_H
#define VIEW_H
class MYGraphicsScene;
class GView;
#include"GView.h"
#include"mygraphicsscene.h"
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
    int scale();

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
    void AdddPortSL();
    void saveImage();
    void AdddPortSL(int x, int y, QString name);

public:

    AddComand* AdddPort();
    AddComand* AdddPort(int x, int y, QString name);

    void stackPush(QUndoCommand* com)
    {
        stack->push(com);
    }
#if QT_CONFIG(wheelevent)
        void wheelEvent(QWheelEvent* e); 
#endif
};

#endif // VIEW_H
