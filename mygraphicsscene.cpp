#include "mygraphicsscene.h"

MYGraphicsScene::MYGraphicsScene(QObject *parent)
    : QGraphicsScene{parent}
{
    setItemIndexMethod(QGraphicsScene::NoIndex);
}

void MYGraphicsScene::drawBackground(QPainter* painter, const QRectF& rect)
{
    QColor col = Qt::black;
    col.setAlpha(50);
    painter->setPen(col);
    const int gridSize = 25;

    qreal left = int(rect.left()) - (int(rect.left()) % gridSize);
    qreal top = int(rect.top()) - (int(rect.top()) % gridSize);

    QVarLengthArray<QLineF, 100> lines;

    for (qreal x = left; x < rect.right(); x += gridSize)
        lines.append(QLineF(x, rect.top(), x, rect.bottom()));
    for (qreal y = top; y < rect.bottom(); y += gridSize)
        lines.append(QLineF(rect.left(), y, rect.right(), y));

    painter->drawLines(lines.data(), lines.size());
}



