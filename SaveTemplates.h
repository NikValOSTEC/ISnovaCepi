#pragma once
#ifndef SAVETEMPLATES_H
#define SAVETEMPLATES_H
#include <QObject>
#include <QFile>
#include <QTextStream>
class PortTwmplateObject;

class SaveTemplates  : public QObject
{
	Q_OBJECT

public:
	SaveTemplates(QObject *parent);
	~SaveTemplates();
	static void Save(QString path, PortTwmplateObject o);
};
#endif
