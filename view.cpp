#include "view.h"
#include "port.h"
#include "proxyrectport.h"
#include "qgraphicsproxywidget.h"
#include <QStyle>
#include"GItemFrame.h"

View::View()
{
    graphicsview = new QGraphicsView(this);
    graphicsview->setRenderHint(QPainter::Antialiasing, false);
    graphicsview->setDragMode(QGraphicsView::RubberBandDrag);
    //graphicsview->setOptimizationFlags(QGraphicsView::OptimizationFlag::IndirectPainting);
    graphicsview->setViewportUpdateMode(QGraphicsView::ViewportUpdateMode::FullViewportUpdate);
    graphicsview->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
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

}


void View::AddPort(int x, int y,QString name)
{
    Port* p = new Port();
    ProxyRectPort* proxyControl = new ProxyRectPort(p);
    proxyControl->geometry(QRectF(x, y + p->height(), p->width(), 30 + p->height()));
    this->GScene()->addItem(proxyControl);
    QGraphicsProxyWidget* const proxy = this->GScene()->addWidget(p);
    proxy->setPos(x, y + proxyControl->boundingRect().height());
    proxy->setParentItem(proxyControl);
    p->name(name);
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
    return (MYGraphicsScene*)graphicsview->scene();
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

QGraphicsView* View::view()
{
    return graphicsview;
}

QMenu* View::ContextMenu()
{
    QMenu* myMenu = new QMenu();    myMenu->addAction("AddPort", this, SLOT(AddPort()));
    return myMenu;
}

void View::showContextMenu(const QPoint& pos)
{
    QPoint globalPos = this->mapToGlobal(pos);
    ContextMenu()->exec(globalPos);
}

void View::AddPort()
{
    QPointF pos = graphicsview->mapToScene(mapFromGlobal(QCursor::pos()));
    AddPort(pos.x(), pos.y(),"");
}
