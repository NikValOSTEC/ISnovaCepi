#include "Dot.h"
#include"NewWhire.h"
#include"pin.h"

Dot::Dot(QGraphicsObject* parent):
	QGraphicsObject(parent)
{
	setFlag(QGraphicsItem::ItemIsMovable, true);
	setFlag(QGraphicsItem::ItemIsSelectable, true);
	setFlag(QGraphicsItem::ItemIsFocusable, true);
	Vdot = nullptr;
	Hdot = nullptr;
	triangle = false;
	Linecounter = 0;
	bg = false;
	this->whires = QVector<NewWhire*>();
	_pin = nullptr;
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

void Dot::setColor(QColor cl)
{
	this->cl = cl;
}

void Dot::setTriangle(bool bl)
{
	triangle = bl;
}

void Dot::setBig(bool bl)
{
	bg = bl;
}

void Dot::setPin(Pin* p)
{
	_pin = p;
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
	if (!triangle)
	{
		path.addEllipse(-3-(bg*3), -3-(bg*3), 6+(bg*6), 6+(bg*6));
	}
	else
	{
		if (pos().x() > _pin->x())
		{
			path.moveTo(0, 0 - _pin->height() / 2);
			path.lineTo(_pin->height() / 2, 0);
			path.lineTo(0, 0 + _pin->height() / 2);
			path.lineTo(0, 0 - _pin->height() / 2);
		}
		else
		{
			path.moveTo(0, 0 - _pin->height() / 2);
			path.lineTo(0-_pin->height() / 2, 0);
			path.lineTo(0, 0 + _pin->height() / 2);
			path.lineTo(0, 0 - _pin->height() / 2);
		}
	}
	return path;
}


void Dot::VerticalDot(Dot* d)
{
	if (qFabs(this->pos().y() - d->pos().y())>2)
	{
		if(_pin==nullptr)
			this->setPos(this->pos().x(), d->pos().y());
		Emit_Moving();
	}
}

void Dot::HorizontalDot(Dot* d)
{
	if (qFabs(this->pos().x() - d->pos().x()) > 2)
	{
		this->setPos(d->pos().x(), this->pos().y());
		Emit_Moving();
	}
}

Pin* Dot::pn()
{
	return _pin;
}
