#include "GItemFrame.h"
#include"mygraphicsscene.h"
#include"GView.h"
GItemFrame::GItemFrame()
{
	setZValue(3);
	setCacheMode(QGraphicsItem::NoCache);
}

GItemFrame::~GItemFrame()
{
	removeFromIndex();
}

QRectF GItemFrame::boundingRect() const
{

	return shape().boundingRect();
}

QPainterPath GItemFrame::shape() const
{
	auto path=QPainterPath();
	auto v=((MYGraphicsScene*)scene())->Mview;
	QRect viewport_rect(0, 0, v->view()->viewport()->width(), v->view()->viewport()->height());
	QRectF visible_scene_rect = v->view()->mapToScene(viewport_rect).boundingRect();
	path.addRect(visible_scene_rect);
	return path;
}

void GItemFrame::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setPen(QPen(Qt::red, 5));
	painter->drawPath(shape());
}
