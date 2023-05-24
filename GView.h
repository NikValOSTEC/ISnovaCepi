#include<qobject.h>
class MyGraphicsScene;
class QGraphicsView;
#include"qgraphicsview.h"
#include"mygraphicsscene.h"
#include<qdrag.h>
#include<qevent.h>

class GView  : public QGraphicsView
{

public:
	GView(QObject *parent);
	~GView();

	MYGraphicsScene* GScene();
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
	void dropEvent(QDropEvent* event)override;
	void dragEnterEvent(QDragEnterEvent* event) override;
	void dragMoveEvent(QDragMoveEvent* event) override;
	int lastselected = 0;
};
