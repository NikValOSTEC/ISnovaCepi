#pragma once
#ifndef SAVETEMPLATES_H
#define SAVETEMPLATES_H
#include <QObject>
#include <QFile>
#include <QTextStream>
#include<qsettings.h>
class PortTwmplateObject;
/// <summary>
/// static сохранение шаблонов
/// </summary>
class SaveTemplates  : public QObject
{
	Q_OBJECT
		
public:
	/// <summary>
	/// сохранение шаблона
	/// </summary>
	/// <param name="o"></param>
	static void Save(PortTwmplateObject* o);
	/// <summary>
	/// выгрузка листа шаблонов
	/// </summary>
	/// <returns></returns>
	static QList<QPair<QStringList, QString>> Load();
	/// <summary>
	/// удаление шаблона
	/// </summary>
	/// <param name="path"></param>
	static void Del(QString path);
};
#endif
