#pragma once
#include<qobject.h>
#include<qwidget.h>
class PortTemplate;
#include"PortTemplate.h"
#include<qpushbutton.h>
class QLineEditFocusOutSignal;
#include"qlineedit.h"


class PortTwmplateObject  : public QWidget
{
	Q_OBJECT

public:
	PortTemplate* templ;
	QPushButton* editpb;
	QPushButton* delpb;
	QLineEditFocusOutSignal* name;
	void dragEnterEvent(QDragEnterEvent* event) override;
	void dropEvent(QDropEvent* event) override;
	void dragMoveEvent(QDragMoveEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;

public slots:
	void editPush();
	void delPush();
	void namecheck(bool foc);
public:
	PortTwmplateObject();
	~PortTwmplateObject();

};
