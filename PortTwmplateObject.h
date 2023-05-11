#pragma once

#include <QWidget>
#include "PortTemplate.h"
#include <qpushbutton.h>
#include <qlineedit.h>
#include"QLineEditFocusOutSignal.h"

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
