#include "minimap.h"

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
    qDebug() << rectt;
    rectt.moveCenter(mapToScene(event->pos()).toPoint());
    qDebug() << rectt;
    v->view()->fitInView(rectt);
    scene()->update();
}

void minimap::rescale()
{
    setMinimumHeight(v->size().height() / sclX);
    setMinimumWidth(v->size().width() / sclY);
    fitInView(scene()->sceneRect(), Qt::KeepAspectRatio);
}

minimap::~minimap()
{}
