#include "SaveTemplates.h"
#include"PortTwmplateObject.h"
#include"PortTemplate.h"
#include"PinTemplate.h"
#include"QLineEditFocusOutSignal.h"
void SaveTemplates::Save(PortTwmplateObject* o)
{
	QSettings settings("settings_demo.conf", QSettings::IniFormat);
	QList<QString> names;
	foreach (auto var, o->templ->pins())
	{
		names.append(var->name());
	}
	settings.beginGroup("Templates");
	settings.setValue(o->name->text(),names);
}

QList<QPair<QStringList,QString>> SaveTemplates::Load()
{

	QSettings settings("settings_demo.conf", QSettings::IniFormat);
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
