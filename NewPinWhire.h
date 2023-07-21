#pragma once
#ifndef NEWPINWHIRE_H
#define NEWPINWHIRE_H
#include<qthread.h>
#include<qobject.h>
class CustomColliderLineRecoursive;
#include"CustomColliderLineRecoursive.h"
class Pin;
/// <summary>
/// �������������� ������ ������ �� ��������
/// <para>
/// ������ ���� � ������� ��������
/// </para>
/// </summary>
class NewPinWhire  : public CustomColliderLineRecoursive
{
	Q_OBJECT
public:
	/// <summary>
	/// ����������� 
	/// <para>
	/// ���� ������� � ����� � ������� ����� ���� ������� 
	/// </para>
	/// <para>
	/// �� ���� ���� ��������� � ��������� �������
	/// </para>
	/// </summary>
	/// <param name="p">������� � �������� �������� ������</param>
	/// <param name="th">����� � ������� �� ���������</param>
	NewPinWhire(Pin* p, QThread* th);
	/// <summary>
	/// ����������
	/// </summary>
	~NewPinWhire();
	/// <summary>
	/// ������� ������ ������
	/// </summary>
	/// <returns> true - ����; false - ���</returns>
	bool hasConection();
	/// <summary>
	/// ���� �������
	/// </summary>
	/// <returns></returns>
	/// 
	


	/// <summary>
	/// ������� �������� ����� ( ������������ )
	/// </summary>
	virtual void ClearInside();


	QColor color() override;
private:
	/// <summary>
	/// ������ � �������� ���� ������
	/// </summary>
	Pin* pin;
};
#endif
