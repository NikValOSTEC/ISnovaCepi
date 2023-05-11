#pragma once

#include <QObject>
#include"PortTwmplateObject.h"
#include <QFile>
#include <QTextStream>

class SaveTemplates  : public QObject
{
	Q_OBJECT

public:
	SaveTemplates(QObject *parent);
	~SaveTemplates();
	static void Save(QString path, PortTwmplateObject o);
};
