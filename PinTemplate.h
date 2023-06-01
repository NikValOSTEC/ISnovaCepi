#pragma once
#ifndef PINTEMPLATE_H
#define PINTEMPLATE_H
#include"pin.h"
class Port;
#include<qobject.h>

class PinTemplate  : public Pin
{
	Q_OBJECT

public:
	PinTemplate(Port* p);
    
//    void initializeGL() {

//    }
//    void paintGL() {
//        glClearColor(1.f, 0.f, 0.f, 1.f);
//        glClear(GL_COLOR_BUFFER_BIT);
//    }
    ~PinTemplate();
};
#endif
