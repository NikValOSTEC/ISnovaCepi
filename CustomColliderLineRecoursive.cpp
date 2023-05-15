#include "CustomColliderLineRecoursive.h"

CustomColliderLineRecoursive::CustomColliderLineRecoursive(bool Vert_f_Horiz_t, Dot* d11, Dot* d22,QGraphicsObject* parent):
	QGraphicsObject(parent)
{
	this->d1 = d11;
	this->d2 = d22;
	d1->WhPl();
	d2->WhPl();
	if (Vert_f_Horiz_t)
	{
		setHorizontal();
	}
	else
	{
		setVertical();
	}

	QObject::connect(d1, SIGNAL(Is_inMove(bool)), this, SLOT(SimpleShape(bool)));
	QObject::connect(d2, SIGNAL(Is_inMove(bool)), this, SLOT(SimpleShape(bool)));
	inside = QVector<QGraphicsObject*>();
}

CustomColliderLineRecoursive::~CustomColliderLineRecoursive()
{
	d1->WhMin();
	d2->WhMin();

	foreach(auto itm, inside)
	{
		auto tm = itm;
		inside.removeOne(itm);
		if (dynamic_cast<CustomColliderLineRecoursive*>(itm))
		{
			delete tm;
		}
		;
	}
}

QRectF CustomColliderLineRecoursive::boundingRect() const
{
	return shape().boundingRect();
}

QPainterPath CustomColliderLineRecoursive::shape() const
{
	QPainterPath path = QPainterPath();
	path.moveTo(d1->x(), d1->y());
	path.lineTo(d2->x(), d2->y());
	return path;
}

void CustomColliderLineRecoursive::FixColliding()
{
	int i = 0;
	auto colitms = collidingItems(Qt::IntersectsItemBoundingRect);
	auto itm = colitms[i];
	auto pr = dynamic_cast<ProxyRectPort*>(itm);
	while (!pr)
	{
		if (i == colitms.count() - 1)
			break;
		i++;
		itm = colitms[i];
		pr = dynamic_cast<ProxyRectPort*>(itm);
	}
	if (pr)
	{
		lastcolide = pr;
		if (!Vertical_f_Horizontal_t)
		{

			Dot* cd1, * cd2, * cd3, * cd4;
			CustomColliderLineRecoursive* d1cd1, * cd1cd2, * cd2cd3, * cd3cd4, * cd4d2;
			cd1 = new Dot();
			cd2 = new Dot();
			cd3 = new Dot();
			cd4 = new Dot();
			inside.append(cd1);
			inside.append(cd2);
			inside.append(cd3);
			inside.append(cd4);
			scene()->addItem(cd1);
			scene()->addItem(cd2);
			scene()->addItem(cd3);
			scene()->addItem(cd4);
			d1cd1 = new CustomColliderLineRecoursive(Vertical_f_Horizontal_t, d1, cd1);
			cd1cd2 = new CustomColliderLineRecoursive(!Vertical_f_Horizontal_t, cd1, cd2);
			cd2cd3 = new CustomColliderLineRecoursive(Vertical_f_Horizontal_t, cd2, cd3);
			cd3cd4 = new CustomColliderLineRecoursive(!Vertical_f_Horizontal_t, cd3, cd4);
			cd4d2 = new CustomColliderLineRecoursive(Vertical_f_Horizontal_t, cd4, d2);
			scene()->addItem(d1cd1);
			scene()->addItem(cd1cd2);
			scene()->addItem(cd2cd3);
			scene()->addItem(cd3cd4);
			scene()->addItem(cd4d2);

			inside.append(d1cd1);
			inside.append(cd1cd2);
			inside.append(cd2cd3);
			inside.append(cd3cd4);
			inside.append(cd4d2);


			auto left = itm->mapToScene(itm->boundingRect().left(), 0).x();
			auto right = itm->mapToScene(itm->boundingRect().right(), 0).x();
			auto bottom = itm->mapToScene(0, itm->boundingRect().bottom()).y();

			lastleft = left;
			lastbottom = bottom;

			cd1->setPos(left - 10, d1->y());
			cd2->setPos(cd1->x(), bottom + 10);
			cd3->setPos(right + 10, cd2->y());
			cd4->setPos(cd3->x(), d2->y());

			qDebug() << cd1->pos() << "    " << cd2->pos() << "     " << cd3->pos() << "      " << cd4->pos();




		}
		else
		{

		}

	}
	else
	{
		this->show();
	}
}

void CustomColliderLineRecoursive::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->drawPath(shape());
}

void CustomColliderLineRecoursive::setFixWay(ColisionFixWay fw)
{
	fixway = fw;
}

void CustomColliderLineRecoursive::setVertical()
{
	Vertical_f_Horizontal_t = false;
	QObject::disconnect(d1, SIGNAL(moving(Dot*)), d2, SLOT(VerticalDot(Dot*)));
	QObject::disconnect(d1, SIGNAL(moving(Dot*)), d2, SLOT(HorizontalDot(Dot*)));
	QObject::disconnect(d2, SIGNAL(moving(Dot*)), d1, SLOT(VerticalDot(Dot*)));
	QObject::disconnect(d2, SIGNAL(moving(Dot*)), d1, SLOT(HorizontalDot(Dot*)));

	QObject::connect(d1, SIGNAL(moving(Dot*)), d2, SLOT(VerticalDot(Dot*)));
	QObject::connect(d2, SIGNAL(moving(Dot*)), d1, SLOT(VerticalDot(Dot*)));
	
}

void CustomColliderLineRecoursive::setHorizontal()
{
	Vertical_f_Horizontal_t = true;
	QObject::disconnect(d1, SIGNAL(moving(Dot*)), d2, SLOT(VerticalDot(Dot*)));
	QObject::disconnect(d1, SIGNAL(moving(Dot*)), d2, SLOT(HorizontalDot(Dot*)));
	QObject::disconnect(d2, SIGNAL(moving(Dot*)), d1, SLOT(VerticalDot(Dot*)));
	QObject::disconnect(d2, SIGNAL(moving(Dot*)), d1, SLOT(HorizontalDot(Dot*)));

	QObject::connect(d1, SIGNAL(moving(Dot*)), d2, SLOT(HorizontalDot(Dot*)));
	QObject::connect(d2, SIGNAL(moving(Dot*)), d1, SLOT(HorizontalDot(Dot*)));
}

void CustomColliderLineRecoursive::SimpleShape(bool bll)
{
	if (bll)
	{
		foreach(auto itm, inside)
		{
			itm->hide();
		}
		this->show();
	}
	else
	{
		bool bl = true;
		foreach (auto var, collidingItems(Qt::IntersectsItemBoundingRect))
		{
			if(dynamic_cast<ProxyRectPort*>(var)==lastcolide&&lastcolide!=nullptr)
			{

				auto left = lastcolide->mapToScene(lastcolide->boundingRect().left(), 0).x();
				auto bottom = lastcolide->mapToScene(0, lastcolide->boundingRect().bottom()).y();
				qDebug() << "   " << left << "   " << lastleft << "   " << bottom << "   " << lastbottom;
				if (left == lastleft && bottom == lastbottom)
				{
					this->hide();
					bl = false;
				}
			}
		}
		if (bl)
		{
			lastcolide = nullptr;
			foreach(auto itm, inside)
			{
				auto tm = itm;
				inside.removeOne(itm);
				if (dynamic_cast<CustomColliderLineRecoursive*>(itm))
				{
					delete tm;
				}
			}
			if (inside.isEmpty())
			{
				this->hide();
				FixColliding();
			}

			QObject::disconnect(d1, SIGNAL(moving(Dot*)), d2, SLOT(VerticalDot(Dot*)));
			QObject::disconnect(d1, SIGNAL(moving(Dot*)), d2, SLOT(HorizontalDot(Dot*)));
			QObject::disconnect(d2, SIGNAL(moving(Dot*)), d1, SLOT(VerticalDot(Dot*)));
			QObject::disconnect(d2, SIGNAL(moving(Dot*)), d1, SLOT(HorizontalDot(Dot*)));
			if (inside.isEmpty())
			{
				if (Vertical_f_Horizontal_t)
					setHorizontal();
				else
					setVertical();
			}
		}
		
		foreach(auto itm, inside)
		{
			itm->show();
		}

	}
}
