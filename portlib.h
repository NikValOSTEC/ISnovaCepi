#pragma once
#ifndef PORTLIB_H
#define PORTLIB_H
#include <QHBoxLayout>

class PortLib  : public QHBoxLayout
{
public:
	PortLib(QObject *parent);
	~PortLib();
};
#endif