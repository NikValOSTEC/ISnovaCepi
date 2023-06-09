#include"GView.h"
#include"qgridlayout.h"
#include"GItemFrame.h"
#include"mygraphicsscene.h"
#include"AddComand.h"
#include "view.h"
#include<QtMath>

View::View()
{
    graphicsview = new GView(this);
    graphicsview->setDragMode(QGraphicsView::RubberBandDrag);
    //graphicsview->setOptimizationFlags(QGraphicsView::OptimizationFlag::IndirectPainting);
    graphicsview->setViewportUpdateMode(QGraphicsView::ViewportUpdateMode::FullViewportUpdate);
    graphicsview->setTransformationAnchor(QGraphicsView::NoAnchor);
    //setFrameStyle(Sunken | StyledPanel);
    GScene(new MYGraphicsScene());
    _scale = 0;
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)),
        this, SLOT(showContextMenu(QPoint)));
    QGridLayout* lay = new QGridLayout();
    lay->addWidget(graphicsview, 1, 0);
    this->setLayout(lay);
    GScene()->addItem((QGraphicsItem*)(new GItemFrame()));
    stack = new QUndoStack();
    auto ctrlZ = new QShortcut(this);   // Инициализируем объект
    ctrlZ->setKey(Qt::Key_Z+ Qt::CTRL);    // Устанавливаем код клавиши
    // цепляем обработчик нажатия клавиши
    connect(ctrlZ, SIGNAL(activated()), this, SLOT(stckUndo()));


    auto ctrlY = new QShortcut(this); 
    // Инициализируем объект
    ctrlY->setKey(Qt::Key_Y+Qt::CTRL );    // Устанавливаем код клавиши
    // цепляем обработчик нажатия клавиши
    connect(ctrlY, SIGNAL(activated()), this, SLOT(stckRedo()));
}




void View::wheelEvent(QWheelEvent* e)
{
    // �������� �� SHIFT ����/�����
    if (e->modifiers() & Qt::SHIFT)
    {
        this->view()->horizontalScrollBar()->setValue(this->view()->horizontalScrollBar()->value() + (e->angleDelta().y()));
    }
    else if (e->modifiers() & Qt::ControlModifier)
    {
        if (e->angleDelta().y() > 0)
            _scale += 6;
        else
            _scale -= 6;
        if (_scale < (-250))
            _scale = -250;
        if (_scale > 250)
            _scale = 250;
        qreal __scale = qPow(qreal(2), _scale / qreal(50));
        QTransform matrix;
        matrix.scale(__scale, __scale);
        this->view()->setTransform(matrix);
    }
    else
    {
        QFrame::wheelEvent(e);
    }
    this->GScene()->update();
}





MYGraphicsScene* View::GScene()
{
    return graphicsview->GScene();
}

void View::GScene(MYGraphicsScene* scene)
{
    graphicsview->setScene(scene);
    scene->Mview = this;
    emit SceneChanged();
}

QColor View::backGroundColor()
{
    return GScene()->backgroundBrush().color();
}

void View::backGroundColor(QColor color)
{
    GScene()->setBackgroundBrush(QBrush(QColor(240, 255, 220)));
}

GView* View::view()
{
    return graphicsview;
}

int View::scale()
{
    return _scale;
}

QMenu* View::ContextMenu()
{
    QMenu* myMenu = new QMenu();    myMenu->addAction("AddPort", this, SLOT(AdddPortSL()));
    return myMenu;
}

void View::showContextMenu(const QPoint& pos)
{
    QPoint globalPos = this->mapToGlobal(pos);
    ContextMenu()->exec(globalPos);
}

void View::stckRedo()
{
    stack->redo();
}

void View::AdddPortSL()
{
    QPoint globalPos = QCursor::pos();
    QPoint pos = graphicsview->mapFromGlobal(globalPos);
    pos = graphicsview->mapToScene(pos).toPoint();
    new AddComand(this, pos.x(), pos.y());
    
}

void View::saveImage()
{
    graphicsview->scene()->clearSelection();                                                  // Selections would also render to the file
    graphicsview->scene()->setSceneRect(graphicsview->scene()->itemsBoundingRect());                          // Re-shrink the scene to it's bounding contents
    QImage image(graphicsview->scene()->sceneRect().size().toSize(), QImage::Format_ARGB32);  // Create the image with the exact size of the shrunk scene
    image.fill(Qt::white);                                              // Start all pixels transparent

    QPainter painter(&image);
    graphicsview->scene()->render(&painter);
    image.save("file_name.png");
}

void View::AdddPortSL(int x, int y, QString name)
{
    new AddComand(this, x, y,name);
}

AddComand* View::AdddPort()
{
    QPoint globalPos = QCursor::pos();
    QPoint pos = graphicsview->mapFromGlobal(globalPos);
    pos = graphicsview->mapToScene(pos).toPoint();
    return new AddComand(this, pos.x(), pos.y());

}

AddComand* View::AdddPort(int x, int y, QString name)
{
    return new AddComand(this, x, y, name);
}




void View::stckUndo()
{
    stack->undo();
}
