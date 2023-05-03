#pragma once

#include "Port.h"
#include"PinTemplate.h"
#include"ui_port.h"
#include <QOpenGLFunctions>
namespace Ui {
	class Port;
}

class PortTemplate  : public Port
{
	Q_OBJECT

public:
	PortTemplate();
	Pin* addPin(QString name = "", int index = -1) override;
	virtual Pin* addPinSl(QString name = "") override;
	virtual void RemoveSL() override;
	~PortTemplate();
	void initializeGL()
	{

		QOpenGLFunctions* f = QOpenGLContext::currentContext()->functions();
		f->glClearColor(240, 240, 240, 1.0f);
	}

	void paintGL()
	{
		QOpenGLFunctions* f = QOpenGLContext::currentContext()->functions();
		f->glClearColor(240, 240, 240, 1.0f);
		f->glClear(GL_COLOR_BUFFER_BIT);
	}
};
