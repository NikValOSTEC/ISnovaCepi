#pragma once
#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H
#include<QGraphicsScene>
#include<QPainter>
#include"view.h"
/// <summary>
/// ��������� �� QGraphicsScene 
/// <para>
/// ����� ��� ��������� zoom in/out; ��� ������� ������� � ��������� ����������� ����� Upcast scene() � graphicsitem; ��� �������� 
/// </para>
/// </summary>
class MYGraphicsScene : public QGraphicsScene
{
public:
    /// <summary>
    /// �������� �����������
    /// </summary>
    View* Mview;
    /// <summary>
    /// Zoom
    /// </summary>
    int _scale = 100;
    /// <summary>
    /// ����������� �����������
    /// </summary>
    /// <param name="parent"></param>
    explicit MYGraphicsScene(QObject *parent = nullptr);
private:
    /// <summary>
    /// ��������� ���������� �������� ��� ����������� ������
    /// </summary>
    int lastselected = 0;
    /// <summary>
    /// ��������
    /// </summary>
    /// <param name="painter"></param>
    /// <param name="rect"></param>
    void drawBackground(QPainter* painter, const QRectF& rect) override;
};

#endif // MYGRAPHICSSCENE_H
