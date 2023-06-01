#pragma once
#ifndef PORTTEMPLATE_H
#define PORTTEMPLATE_H
#include"qobject.h"
#include"ui_port.h"
#include <qopenglfunctions.h>
#include"port.h"
class Pin;

namespace Ui {
	class Port;
}

class PortTemplate  : public Port
{
	Q_OBJECT

public:
	PortTemplate();
	Pin* addPinn(QString name = "", int index = -1);
	~PortTemplate();
private slots:
	Pin* addPinSl(QString name = "");
	void RemoveSL();

//	void initializeGL()
//	{

//		QOpenGLFunctions* f = QOpenGLContext::currentContext()->functions();
//		f->glClearColor(240, 240, 240, 1.0f);
//	}

//	void paintGL()
//	{
//		QOpenGLFunctions* f = QOpenGLContext::currentContext()->functions();
//		f->glClearColor(240, 240, 240, 1.0f);
//		f->glClear(GL_COLOR_BUFFER_BIT);
//	}


    virtual QMenu* ContextMenu();
};
#endif
