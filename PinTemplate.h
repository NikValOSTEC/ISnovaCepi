#pragma once

#include "Pin.h"

class PinTemplate  : public Pin
{
	Q_OBJECT

public:
	PinTemplate(Port* p);
    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void dragEnterEvent(QDragEnterEvent* event) override;
    virtual void dropEvent(QDropEvent* event) override;
    virtual void dragMoveEvent(QDragMoveEvent* event) override;
//    void initializeGL() {

//    }
//    void paintGL() {
//        glClearColor(1.f, 0.f, 0.f, 1.f);
//        glClear(GL_COLOR_BUFFER_BIT);
//    }
    ~PinTemplate();
};
