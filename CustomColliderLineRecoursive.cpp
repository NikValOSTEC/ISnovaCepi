
#include "CustomColliderLineRecoursive.h"
#include"Dot.h"
#include"proxyrectport.h"
#include"pin.h"
#include"port.h"
#include<QDebug>
#include <QRandomGenerator>
CustomColliderLineRecoursive::CustomColliderLineRecoursive(bool Vert_f_Horiz_t, Dot* d11, Dot* d22,CustomColliderLineRecoursive* parent):
	QGraphicsObject()
{
	setCacheMode(QGraphicsItem::NoCache);
	setZValue(-1);
	this->d1 = d11;
	this->d2 = d22;
	d1->WhPl();
	setVisible(true);
	d2->WhPl();
	if (Vert_f_Horiz_t)
	{
		setHorizontal();
	}
	else
	{
		setVertical();
	}
	inside = QVector<QGraphicsObject*>();
	itsmine = QVector<QGraphicsItem*>();
	Parent = parent;
	r = QRandomGenerator::global()->bounded(0, 255);
	g = QRandomGenerator::global()->bounded(0, 255);
	b = QRandomGenerator::global()->bounded(0, 255);
	if (Parent != nullptr)
	{
		itsmine.append(Parent->itsmine);
	}
}

CustomColliderLineRecoursive::~CustomColliderLineRecoursive()
{

	if (d1->Hdot == this)
		d1->Hdot = nullptr;
	if (d2->Hdot == this)
		d2->Hdot = nullptr;

    foreach(auto itm, inside)
    {
        auto tm = itm;
        inside.removeOne(itm);
        if (dynamic_cast<CustomColliderLineRecoursive*>(itm))
        {
            delete tm;
        }
    }
        QObject::disconnect(d2, SIGNAL(moving(Dot*)), d1, SLOT(VerticalDot(Dot*)));
        
		QObject::disconnect(d2, SIGNAL(moving(Dot*)), d1, SLOT(HorizontalDot(Dot*)));
        
		QObject::disconnect(d1, SIGNAL(moving(Dot*)), d2, SLOT(VerticalDot(Dot*)));
        
		QObject::disconnect(d1, SIGNAL(moving(Dot*)), d2, SLOT(HorizontalDot(Dot*)));


	d2->WhMin();
	d1->WhMin();
}

QRectF CustomColliderLineRecoursive::boundingRect() const
{
	if(!this->isVisible())
		return QRectF(d1->x(), d1->y(), d1->x(), d1->y());
	return QRectF(QPointF(d1->x() + 1, d1->y() + 1), QPointF(d2->x() - 1, d2->y() - 1));
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
	int mines = 0;
	auto colitms = collidingItems(Qt::IntersectsItemBoundingRect);
	auto itm = colitms[i];
	auto pr = dynamic_cast<ProxyRectPort*>(itm);
	foreach (auto var,colitms)
	{
		if (auto cl = dynamic_cast<CustomColliderLineRecoursive*>(var))
		{
			if (Parent != nullptr)
			{
				if (Parent!=cl&&!Parent->inside.contains(cl))
					JumpFrom(cl);
			}
		}
	}
	while (!pr || (itsmine.contains(itm)))
	{
		if (i == colitms.count() - 1)
			break;
		i++;
		itm = colitms[i];
		pr = dynamic_cast<ProxyRectPort*>(itm);

	}
	if (!Vertical_f_Horizontal_t) 
	{
		if (pr)
		{
			ClearInside();
			this->hide();

			if ((d1->pn() == nullptr || (pr != d1->pn()->parCon->proxy())) && (d2->pn() == nullptr || pr != d2->pn()->parCon->proxy()))
			{
				itsmine.append(pr);
				lastcolide = pr;
				if (!Vertical_f_Horizontal_t)
				{
					Dot* cd1, * cd2, * cd3, * cd4;
					CustomColliderLineRecoursive* d1cd1, * cd1cd2, * cd2cd3, * cd3cd4, * cd4d2;
					cd1 = new Dot();
					cd2 = new Dot();
					cd3 = new Dot();
					cd4 = new Dot();
					QObject::disconnect(d1, SIGNAL(moving(Dot*)), d2, SLOT(VerticalDot(Dot*)));
					QObject::disconnect(d1, SIGNAL(moving(Dot*)), d2, SLOT(HorizontalDot(Dot*)));
					QObject::disconnect(d2, SIGNAL(moving(Dot*)), d1, SLOT(VerticalDot(Dot*)));
					QObject::disconnect(d2, SIGNAL(moving(Dot*)), d1, SLOT(HorizontalDot(Dot*)));
					inside.append(cd1);
					inside.append(cd2);
					inside.append(cd3);
					inside.append(cd4);
					scene()->addItem(cd1);
					scene()->addItem(cd2);
					scene()->addItem(cd3);
					scene()->addItem(cd4);
					auto left = itm->mapToScene(itm->boundingRect().left(), 0).x();
					auto right = itm->mapToScene(itm->boundingRect().right(), 0).x();
					auto bottom = itm->mapToScene(0, itm->boundingRect().bottom()).y();

					lastleft = left;
					lastbottom = bottom;
					if (d1->x() < d2->x())
					{
						cd1->setPos(left - 10, d1->y());
						cd2->setPos(cd1->x(), bottom + 10);
						cd3->setPos(right + 10, cd2->y());
						cd4->setPos(cd3->x(), d2->y());
					}
					else
					{
						cd1->setPos(right + 10, d1->y());
						cd2->setPos(cd1->x(), bottom + 10);
						cd3->setPos(left - 10, cd2->y());
						cd4->setPos(cd3->x(), d2->y());
					}
					d1cd1 = new CustomColliderLineRecoursive(Vertical_f_Horizontal_t, d1, cd1, this);
					cd1cd2 = new CustomColliderLineRecoursive(!Vertical_f_Horizontal_t, cd1, cd2, this);
					cd2cd3 = new CustomColliderLineRecoursive(Vertical_f_Horizontal_t, cd2, cd3, this);
					cd3cd4 = new CustomColliderLineRecoursive(!Vertical_f_Horizontal_t, cd3, cd4, this);
					cd4d2 = new CustomColliderLineRecoursive(Vertical_f_Horizontal_t, cd4, d2, this);

					connect(pr, SIGNAL(strartMove()), this, SLOT(FixColliding()), Qt::DirectConnection);

					if (!Vertical_f_Horizontal_t)
					{
						cd2->Hdot = cd2cd3;
						cd3->Hdot = cd2cd3;
					}
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


					qDebug() << d1->pos() << d2->pos();
					qDebug() << cd1->pos() << cd2->pos()<< cd3->pos() << cd4->pos();;
					d1cd1->FixColliding();
					cd1cd2->FixColliding();
					cd2cd3->FixColliding();
					cd3cd4->FixColliding();
					cd4d2->FixColliding();




				}
				else
				{
					JumpFrom(pr);
				}
			}



		}
		else
		{

			ClearInside();
		}
	}
	else if(pr)
		JumpFrom(pr);

	d1->Emit_Moving();
	d2->Emit_Moving();
}

void CustomColliderLineRecoursive::ClearInside()
{
	foreach(auto vr, this->inside)
	{
		if (dynamic_cast<CustomColliderLineRecoursive*>(vr))
		{
			delete vr;
		}
	}
	inside.clear();
	this->show();
	lastcolide = nullptr;
	itsmine.clear();
	if (Vertical_f_Horizontal_t)
	{

		d1->Hdot = this;
		d2->Hdot = this;
		QObject::connect(d1, SIGNAL(moving(Dot*)), d2, SLOT(HorizontalDot(Dot*)));
		QObject::connect(d2, SIGNAL(moving(Dot*)), d1, SLOT(HorizontalDot(Dot*)));
	}
	else
	{

		d1->Vdot = this;
		d2->Vdot = this;
		QObject::connect(d1, SIGNAL(moving(Dot*)), d2, SLOT(VerticalDot(Dot*)));
		QObject::connect(d2, SIGNAL(moving(Dot*)), d1, SLOT(VerticalDot(Dot*)));
	}
}

void CustomColliderLineRecoursive::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	qDebug() << d1->pos() << d2->pos();
	painter->drawPath(shape());
	painter->setPen(QColor(r,g,b));
	painter->drawRect(boundingRect());
}

void CustomColliderLineRecoursive::setFixWay(ColisionFixWay fw)
{
	fixway = fw;
}

void CustomColliderLineRecoursive::setVertical()
{
    Vertical_f_Horizontal_t = false;
	d1->Vdot = this;
	d2->Vdot = this;

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
	d1->Hdot = this;
	d2->Hdot = this;

    QObject::disconnect(d1, SIGNAL(moving(Dot*)), d2, SLOT(VerticalDot(Dot*)));
    QObject::disconnect(d1, SIGNAL(moving(Dot*)), d2, SLOT(HorizontalDot(Dot*)));
    QObject::disconnect(d2, SIGNAL(moving(Dot*)), d1, SLOT(VerticalDot(Dot*)));
    QObject::disconnect(d2, SIGNAL(moving(Dot*)), d1, SLOT(HorizontalDot(Dot*)));

    QObject::connect(d1, SIGNAL(moving(Dot*)), d2, SLOT(HorizontalDot(Dot*)));
    QObject::connect(d2, SIGNAL(moving(Dot*)), d1, SLOT(HorizontalDot(Dot*)));
}

void CustomColliderLineRecoursive::JumpFrom(QGraphicsItem* itm)
{
	if (this->collidesWithItem(itm))
	{
		if (auto pc = dynamic_cast<ProxyRectPort*>(itm))
		{
			if (this->Vertical_f_Horizontal_t)
			{
				if (d1->Hdot != nullptr)
				{
					if (d1->Hdot->d1 == d1)
					{
						if (d1->Hdot->d2->x() < d1->x())
						{
							d1->setPos(pc->right() + 10, d1->y());
						}
						else
							d1->setPos(pc->left() - 10, d1->y());
					}
					else if (d1->Hdot->d2 == d1)
					{
						if (d1->Hdot->d1->x() < d1->x())
						{
							d1->setPos(pc->right() + 10, d1->y());
						}
						else
							d1->setPos(pc->left() - 10, d1->y());
					}

					d1->Emit_Moving();
				}
				else if (d2->Hdot != nullptr)
				{
					if (d2->Hdot->d1 == d2)
					{
						if (d2->Hdot->d2->x() < d2->x())
						{
							d2->setPos(pc->right() + 10, d2->y());
						}
						else
							d2->setPos(pc->left() - 10, d2->y());
					}
					else if (d2->Hdot->d2 == d2)
					{
						if (d2->Hdot->d1->x() < d2->x())
						{
							d2->setPos(pc->right() + 10, d2->y());
						}
						else
							d2->setPos(pc->left() - 10, d2->y());
					}
					d2->Emit_Moving();

				}
			}
			else
			{
				if (d1->pos().y() > pc->center().y())
				{
					d1->setPos(d1->pos().x(), pc->bottom() + 10);
					d1->Emit_Moving();
				}
				else
				{

					d1->setPos(d1->pos().x(), pc->top() - 10);
				}
			}
		}
		else if (auto cl = dynamic_cast<CustomColliderLineRecoursive*>(itm))
		{
			if (cl->Vertical_f_Horizontal_t == Vertical_f_Horizontal_t)
			{
				if (Vertical_f_Horizontal_t)
				{
					d1->setY(d1->y() + 10);
					d1->Emit_Moving();
				}
				else

				{
					d1->setX(d1->x() + 10);
					d1->Emit_Moving();
				}
			}
		}
	}
}