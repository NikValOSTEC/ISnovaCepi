#pragma once
#ifndef VIEW_H
#define VIEW_H
#include<qshortcut.h>
#include<qundostack.h>
#include<qscrollbar.h>
#include<QMenu>
#include<qframe.h>
class GView;
class MYGraphicsScene;
class AddComand;
/// <summary>
/// "Дисплей" с вложеным отображением 
/// </summary>
class View : public QFrame
{
    Q_OBJECT
public:
    /// <summary>
    /// Создает Frame с вложенным View 
    /// </summary>
    View();
    /// <summary>
    /// Сцена вложенная в отображение
    /// </summary>
    /// <returns></returns>
    MYGraphicsScene* GScene();
    /// <summary>
    /// установка сцены в отображение
    /// </summary>
    /// <param name="scene"></param>
    void GScene(MYGraphicsScene* scene);
    /// <summary>
    /// цвет фона
    /// </summary>
    /// <returns></returns>
    QColor backGroundColor();
    /// <summary>
    /// установка цвета фона
    /// </summary>
    /// <param name="color"></param>
    void backGroundColor(QColor color);
    /// <summary>
    /// Отображение в Frame
    /// </summary>
    /// <returns></returns>
    GView* view();
    /// <summary>
    /// Undo|Redo stack
    /// </summary>
    QUndoStack* stack;
    /// <summary>
    /// Маштаб
    /// </summary>
    /// <returns></returns>
    int scale();

protected:
    /// <summary>
    /// отображение
    /// </summary>
    GView* graphicsview;
    int _scale;
    /// <summary>
    /// Добовление Разъема контекстное меню
    /// </summary>
    /// <returns></returns>
    virtual QMenu* ContextMenu();
protected slots:
    /// <summary>
    ///  Добовление Разъема контекстное меню
    /// </summary>
    virtual void showContextMenu(const QPoint& pos);
signals:
    /// <summary>
    /// Сигнал на изменение сцены
    /// </summary>
    void SceneChanged();
public slots:
    /// <summary>
    /// Undo Redo
    /// </summary>
    void stckUndo();
    /// <summary>
    /// Undo Redo
    /// </summary>
    void stckRedo();
    /// <summary>
    /// Добовление разъема
    /// </summary>
    void AdddPortSL();
    /// <summary>
    /// Coxранение скриншота
    /// </summary>
    void saveImage();
    /// <summary>
    /// Добовление разъема
    /// </summary>
    void AdddPortSL(int x, int y, QString name);

public:

    /// <summary>
    /// Добовление разъема
    /// </summary>
    AddComand* AdddPort();
    /// <summary>
    /// Добовление разъема
    /// </summary>
    AddComand* AdddPort(int x, int y, QString name);

    /// <summary>
    /// Undo Redo
    /// </summary>
    void stackPush(QUndoCommand* com)
    {
        stack->push(com);
    }
#if QT_CONFIG(wheelevent)
        /// <summary>
        /// ZOOM in|out
        /// </summary>
        /// <param name="e"></param>
        void wheelEvent(QWheelEvent* e); 
#endif
};

#endif // VIEW_H
