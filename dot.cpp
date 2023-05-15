#include "Dot.h"

Dot::Dot(QGraphicsObject* parent):
	QGraphicsObject(parent)
{
	setFlag(QGraphicsItem::ItemIsMovable, true);
	setFlag(QGraphicsItem::ItemIsSelectable, true);
	setFlag(QGraphicsItem::ItemIsFocusable, true);
}

int Dot::type() const
{
	return 102;
}

int Dot::x()
{
	return pos().x();
}

int Dot::y()
{
	return pos().y();
}

void Dot::x(int x)
{
	setPos(x, pos().y());
}

void Dot::y(int y)
{
	setPos(pos().x(),y);
}

Dot::~Dot()
{

}

void Dot::WhPl()
{
	Linecounter++;
}

void Dot::WhMin()
{
	Linecounter--;
	if (Linecounter < 1)
	{
		delete this;
	}
}

void Dot::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setBrush(QBrush(QColor(137, 224, 8)));
	painter->drawPath(shape());
}

QRectF Dot::boundingRect() const
{
	return shape().boundingRect();
}

QPainterPath Dot::shape() const
{
	QPainterPath path = QPainterPath();
	path.addEllipse(-5, -5, 10, 10);
	return path;
}


void Dot::VerticalDot(Dot* d)
{
	this->setPos(this->pos().x(), d->pos().y());
}

void Dot::HorizontalDot(Dot* d)
{

	this->setPos(d->pos().x(),this->pos().y());
}
