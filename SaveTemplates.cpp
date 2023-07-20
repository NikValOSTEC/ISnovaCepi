#include "SaveTemplates.h"
#include"PortTwmplateObject.h"
#include"PortTemplate.h"
#include"PinTemplate.h"
#include"qlineedit.h"
void SaveTemplates::Save(PortTwmplateObject* o)
{
	QSettings settings("./settings_demo.conf", QSettings::IniFormat);
	QList<QString> names;
	foreach (auto var, o->templ->pins())
	{
		names.append(var->name());
	}
	settings.beginGroup("Templates");
	int i = 1;
	auto nm = o->templ->name();
	if (settings.allKeys().contains(nm))
	{
		while (settings.allKeys().contains(nm=nm + "(" + QString::number(i) + ")"))
		{
			
		}
		o->templ->name(nm);
	}
	settings.setValue(o->templ->name(), names);
	settings.endGroup();
	settings.sync();
}

QList<QPair<QStringList,QString>> SaveTemplates::Load()
{

	QSettings settings("./settings_demo.conf", QSettings::IniFormat);
	QList<QPair<QStringList, QString>> lst = QList<QPair<QStringList, QString>>();
	auto keys=settings.allKeys();
	foreach(auto k, keys)
	{
		auto kk = k;
		kk.remove("Templates/");
		lst.append(QPair<QStringList, QString>(qvariant_cast<QStringList>(settings.value(k)), kk));
	}
	return lst;
}

void SaveTemplates::Del(QString name)
{
	QSettings settings("./settings_demo.conf", QSettings::IniFormat);	
	settings.beginGroup("Templates");
	settings.remove("Templates/" + name);
	settings.endGroup();
	settings.sync();
}
