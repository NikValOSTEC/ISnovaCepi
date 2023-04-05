#include "view.h"
#include "port.h"
#include "proxyrectport.h"
#include "qgraphicsproxywidget.h"
#include <QStyle>

View::View()
{
    graphicsview=new QGraphicsView(this);
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

}

MYGraphicsScene *View::GScene()
{
    return (MYGraphicsScene*)graphicsview->scene();
}

void View::GScene(MYGraphicsScene* scene)
{
    graphicsview->setScene(scene);
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

QGraphicsView *View::view()
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
    Port* p=new Port();
    QPointF pos = graphicsview->mapToScene(mapFromGlobal(QCursor::pos()));
    ProxyRectPort* proxyControl = new ProxyRectPort(p);
    proxyControl->geometry(QRectF(pos.x()-2, pos.y()+p->height(), p->width()+4, 30+p->height()));
    this->GScene()->addItem(proxyControl);
    QGraphicsProxyWidget* const proxy = this->GScene()->addWidget(p);
    proxy->setPos(pos.x(), pos.y() + proxyControl->boundingRect().height());
    proxy->setParentItem(proxyControl);
}
