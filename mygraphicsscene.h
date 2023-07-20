#pragma once
#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H
#include<QGraphicsScene>
#include<QPainter>
#include"view.h"
/// <summary>
/// Наследник от QGraphicsScene 
/// <para>
/// Нужен для пересчета zoom in/out; для прямого доступа к основному отображению через Upcast scene() в graphicsitem; для клеточек 
/// </para>
/// </summary>
class MYGraphicsScene : public QGraphicsScene
{
public:
    /// <summary>
    /// Основное отображение
    /// </summary>
    View* Mview;
    /// <summary>
    /// Zoom
    /// </summary>
    int _scale = 100;
    /// <summary>
    /// Стандартный конструктор
    /// </summary>
    /// <param name="parent"></param>
    explicit MYGraphicsScene(QObject *parent = nullptr);
private:
    /// <summary>
    /// выделение нескольких разъемов для перемещения группы
    /// </summary>
    int lastselected = 0;
    /// <summary>
    /// Клеточки
    /// </summary>
    /// <param name="painter"></param>
    /// <param name="rect"></param>
    void drawBackground(QPainter* painter, const QRectF& rect) override;
};

#endif // MYGRAPHICSSCENE_H
