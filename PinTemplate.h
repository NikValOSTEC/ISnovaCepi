#pragma once
#ifndef PINTEMPLATE_H
#define PINTEMPLATE_H
#include"pin.h"
class Port;
#include<qobject.h>
/// <summary>
/// ������� �� �������� (����������) 
/// <para>
/// ��������� ������� ���
/// </para>
/// </summary>
class PinTemplate  : public Pin
{
	Q_OBJECT

public:
	/// <summary>
	/// ����������� Pin
	/// </summary>
	/// <param name="p">������ � ������� ����� ������� (� ������� ��������� ������)</param>
	PinTemplate(Port* p);
    /// <summary>
    /// ���������� ����������� ���
    /// </summary>
    /// <param name="event"></param>
    virtual void dragEnterEvent(QDragEnterEvent* event) override;
    /// <summary>
    /// ���������� ����������� ���
    /// </summary>
    virtual void dropEvent(QDropEvent* event) override;
    /// <summary>
    /// ���������� ����������� ���
    /// </summary>
    virtual void dragMoveEvent(QDragMoveEvent* event) override;
    /// <summary>
    /// ����������
    /// </summary>
    ~PinTemplate();
};
#endif
