#include "view.h"
#include "port.h"
#include "proxyrectport.h"
#include "qgraphicsproxywidget.h"
#include <QStyle>
#include<qpainter.h>

View::View()
{
    this->setRenderHint(QPainter::Antialiasing, false);
    this->setDragMode(QGraphicsView::RubberBandDrag);
    //graphicsview->setOptimizationFlags(QGraphicsView::OptimizationFlag::IndirectPainting);
    this->setViewportUpdateMode(QGraphicsView::ViewportUpdateMode::FullViewportUpdate);
    this->setRenderHint(QPainter::RenderHint::VerticalSubpixelPositioning);
    this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    //setFrameStyle(Sunken | StyledPanel);
    GScene(new MYGraphicsScene());
    _scale = 0;
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)),
        this, SLOT(showContextMenu(QPoint)));
}

MYGraphicsScene *View::GScene()
{
    return (MYGraphicsScene*)this->scene();
}

void View::GScene(MYGraphicsScene* scene)
{
    this->setScene(scene);
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

void View::mouseMoveEvent(QMouseEvent* mouseEvent)
{
    QList<QGraphicsItem*> items = GScene()->selectedItems();
    for (int i = 0; i < items.count(); i++)
    {

        if (items[i]->type() == 100)
        {
            ((dot*)items[i])->Uupdate();

        }
        else if (items[i]->type() == 101)
        {
            ((ProxyRectPort*)items[i])->Update();
        }
    }
    QGraphicsView::mouseMoveEvent(mouseEvent);
}

void View::mouseReleaseEvent(QMouseEvent* mouseEvent)
{
    QList<QGraphicsItem*> items = GScene()->selectedItems();
    for (int i = 0; i < items.count(); i++)
    {
        if (items[i]->type() == 100)
        {
            ((dot*)items[i])->Uupdate(true);

        }
        else if (items[i]->type() == 101)
        {
            ((ProxyRectPort*)items[i])->Update();
        }
    }

    QGraphicsView::mouseReleaseEvent(mouseEvent);
}


QMenu* View::ContextMenu()
{
    QMenu* myMenu = new QMenu();    
    myMenu->addAction("AddPort", this, SLOT(AddPort()));
    return myMenu;
}

void View::wheelEvent(QWheelEvent* e)
{

    // Смешение по SHIFT лево/право
    if (e->modifiers() & Qt::SHIFT)
    {
        this->horizontalScrollBar()->setValue(this->horizontalScrollBar()->value() + (e->angleDelta().y()));
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
        this->setTransform(matrix);
    }
    else
    {
        QFrame::wheelEvent(e);
    }
    this->scene()->update();
}

void View::showContextMenu(const QPoint& pos)
{
    QPoint globalPos = this->mapToGlobal(pos);
    ContextMenu()->exec(globalPos);
}

void View::AddPort()
{
    Port* p=new Port();
    QPointF pos = this->mapToScene(mapFromGlobal(QCursor::pos()));
    ProxyRectPort* proxyControl = new ProxyRectPort(p);
    proxyControl->geometry(QRectF(pos.x()-2, pos.y()+p->height(), p->width()+4, 30+p->height()));
    this->GScene()->addItem(proxyControl);
    QGraphicsProxyWidget* const proxy = this->GScene()->addWidget(p);
    proxy->setPos(pos.x(), pos.y() + proxyControl->boundingRect().height());
    proxy->setParentItem(proxyControl);
}
