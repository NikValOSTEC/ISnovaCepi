#include <QApplication>
#include <QtDebug>
#include <QFile>
#include <QTextStream>
#include<stdlib.h>
#ifndef MESSAGEHENDLER_H
#define MESSAGEHENDLER_H
void myMessageHandler(const char* msg, QtMsgType type = QtDebugMsg);
#endif 