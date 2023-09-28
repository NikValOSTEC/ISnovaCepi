#include "minimap.h"
#include"view.h"
#include"GView.h"
#include"mygraphicsscene.h"
#include<QDebug>
minimap::minimap(View* v)
{
    this->v = v;
	this->setScene(v->GScene());    
    connect(v->GScene(), SIGNAL(changed(const QList<QRectF> &)), this, SLOT(rescale()));
    setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    sclX = 2;
    sclY = 2;

    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)),
        this, SLOT(showContextMenu(QPoint)));
}

void minimap::mouseMoveEvent(QMouseEvent* event)
{
	
}

void minimap::mouseReleaseEvent(QMouseEvent* event)
{
}

void minimap::mousePressEvent(QMouseEvent* event)
{
    auto rectt = v->view()->rect();
    rectt.moveCenter(mapToScene(event->pos()).toPoint());
    v->view()->fitInView(rectt);
    scene()->update();
}

void minimap::mouseDoubleClickEvent(QMouseEvent* event)
{
}

void minimap::wheelEvent(QWheelEvent* e)
{
    fitInView(scene()->itemsBoundingRect(), Qt::KeepAspectRatio);
}

void minimap::rescale()
{
    setFixedHeight(v->size().height() / sclX);
    setFixedWidth(v->size().width() / sclY);
    /*scene()->setSceneRect(scene()->itemsBoundingRect());*/
    fitInView(scene()->itemsBoundingRect(), Qt::KeepAspectRatio);
}

minimap::~minimap()
{
}
