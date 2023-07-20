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
/// "�������" � �������� ������������ 
/// </summary>
class View : public QFrame
{
    Q_OBJECT
public:
    /// <summary>
    /// ������� Frame � ��������� View 
    /// </summary>
    View();
    /// <summary>
    /// ����� ��������� � �����������
    /// </summary>
    /// <returns></returns>
    MYGraphicsScene* GScene();
    /// <summary>
    /// ��������� ����� � �����������
    /// </summary>
    /// <param name="scene"></param>
    void GScene(MYGraphicsScene* scene);
    /// <summary>
    /// ���� ����
    /// </summary>
    /// <returns></returns>
    QColor backGroundColor();
    /// <summary>
    /// ��������� ����� ����
    /// </summary>
    /// <param name="color"></param>
    void backGroundColor(QColor color);
    /// <summary>
    /// ����������� � Frame
    /// </summary>
    /// <returns></returns>
    GView* view();
    /// <summary>
    /// Undo|Redo stack
    /// </summary>
    QUndoStack* stack;
    /// <summary>
    /// ������
    /// </summary>
    /// <returns></returns>
    int scale();

protected:
    /// <summary>
    /// �����������
    /// </summary>
    GView* graphicsview;
    int _scale;
    /// <summary>
    /// ���������� ������� ����������� ����
    /// </summary>
    /// <returns></returns>
    virtual QMenu* ContextMenu();
protected slots:
    /// <summary>
    ///  ���������� ������� ����������� ����
    /// </summary>
    virtual void showContextMenu(const QPoint& pos);
signals:
    /// <summary>
    /// ������ �� ��������� �����
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
    /// ���������� �������
    /// </summary>
    void AdddPortSL();
    /// <summary>
    /// Cox������� ���������
    /// </summary>
    void saveImage();
    /// <summary>
    /// ���������� �������
    /// </summary>
    void AdddPortSL(int x, int y, QString name);

public:

    /// <summary>
    /// ���������� �������
    /// </summary>
    AddComand* AdddPort();
    /// <summary>
    /// ���������� �������
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
