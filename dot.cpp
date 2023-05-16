#include "Dot.h"

Dot::Dot(QGraphicsObject* parent):
	QGraphicsObject(parent)
{
	setFlag(QGraphicsItem::ItemIsMovable, true);
	setFlag(QGraphicsItem::ItemIsSelectable, true);
	setFlag(QGraphicsItem::ItemIsFocusable, true);
	Vdot = nullptr;
	Hdot = nullptr;
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
	painter->setBrush(QBrush(cl));
	painter->drawPath(shape());
}

QRectF Dot::boundingRect() const
{
	return shape().boundingRect();
}

QPainterPath Dot::shape() const
{
	QPainterPath path = QPainterPath();
	path.addEllipse(-7, -7, 14, 14);
	return path;
}


void Dot::VerticalDot(Dot* d)
{
	if (this->pos().y() != d->pos().y())
	{
		this->setPos(this->pos().x(), d->pos().y());

		Emit_Moving();
	}
}

void Dot::HorizontalDot(Dot* d)
{
	if (this->pos().x() != d->pos().x())
	{
		this->setPos(d->pos().x(), this->pos().y());
		Emit_Moving();
	}
}
