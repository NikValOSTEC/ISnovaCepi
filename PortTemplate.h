#pragma once
#ifndef PORTTEMPLATE_H
#define PORTTEMPLATE_H
#include"qobject.h"
#include"ui_port.h"
#include <qopenglfunctions.h>
#include"port.h"
class PortTwmplateObject;
class SaveTemplates;
class Pin;

namespace Ui {
	class Port;
}

/// <summary>
/// ������ �������; ���������� ������� ( ������ ����������� ���)
/// </summary>
class PortTemplate  : public Port
{
	Q_OBJECT

public:
	/// <summary>
	/// ����� ������ hfp]tvf
	/// </summary>
	/// <param name="o">������ ��� Drag and Drop</param>
	PortTemplate(PortTwmplateObject* o);
	/// <summary>
	/// ���������� �������� (������� ��������)
	/// </summary>
	/// <param name="name"></param>
	/// <param name="index"></param>
	/// <returns>����������� �������</returns>
	Pin* addPinn(QString name = "", int index = -1);
	/// <summary>
	/// ����������
	/// </summary>
	~PortTemplate();
private:
	/// <summary>
	/// ������ ��� Drag and Drop
	/// </summary>
	PortTwmplateObject* object;
private slots:
	/// <summary>
	/// ���������� ��������
	/// </summary>
	Pin* addPinSl(QString name = "");
	/// <summary>
	/// �������� �������
	/// </summary>
	void RemoveSL();
	/// <summary>
	/// �������� ���� �������������� ������� (����������)
	/// </summary>
	/// <param name="event"></param>
	void closeEvent(QCloseEvent* event) override;
    /// <summary>
    /// ����������� ����
    /// </summary>
    /// <returns></returns>
    virtual QMenu* ContextMenu();
};
#endif
