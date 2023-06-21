#pragma once
#ifndef SAVETEMPLATES_H
#define SAVETEMPLATES_H
#include <QObject>
#include <QFile>
#include <QTextStream>
#include<qsettings.h>
class PortTwmplateObject;

class SaveTemplates  : public QObject
{
	Q_OBJECT
		
public:
	static void Save(PortTwmplateObject* o);
	static QList<QPair<QStringList, QString>> Load();
	static void Del(QString path);
};
#endif
