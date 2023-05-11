#include "SaveTemplates.h"

SaveTemplates::SaveTemplates(QObject *parent)
	: QObject(parent)
{}

SaveTemplates::~SaveTemplates()
{}

void SaveTemplates::Save(QString path, PortTwmplateObject o)
{
    QString filename = path;
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << o.name->text() << char(0);
        stream << o.templ->name() << char(0);
        foreach (auto var, o.templ->pins())
        {
            stream << var << char(0);
        }

    }
    file.close();
}
