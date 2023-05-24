
#include"qgraphicsitem.h"
class GItemFrame  : public  QGraphicsItem
{

public:
	GItemFrame();
	~GItemFrame();
	QRectF boundingRect() const override;//
	QPainterPath shape() const override;//
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

};
