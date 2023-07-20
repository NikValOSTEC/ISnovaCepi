#ifndef NEWWHIRE_H
#define NEWWHIRE_H
#pragma once
#include"CustomColliderLineRecoursive.h"
class Pin;
class AddWhireCommand;
class Chain;
/// <summary>
/// ������������ ������ ����������� 2 �������� 
/// 
/// <para>
/// ��������� 2 ������� ����� NewPinWhire 
/// </para>
/// </summary>
class NewWhire  : public CustomColliderLineRecoursive
{
	//Q_OBJECT
public:
	/// <summary>
	/// �������� ����������� ��������
	/// </summary>
	Pin *p1 = nullptr, *p2 = nullptr;
	/// <summary>
	/// ���� � ������� ������ ������ ������ � ����������� �� ��������
	/// </summary>
	Chain* chain = nullptr;
	/// <summary>
	/// ��������� ������ �� �����
	/// </summary>
	/// <param name="pp1">������ �������</param>
	/// <param name="pp2">������� �������</param>
	/// <param name="comm">������� Undo � ������� ��������� ������ (���������� �� com ��� this)</param>
	NewWhire(Pin*pp1,Pin*pp2,AddWhireCommand* comm);
	/// <summary>
	/// ����������
	/// </summary>
	~NewWhire();
	/// <summary>
	/// ������� Undo �������� �������
	/// </summary>
	AddWhireCommand* command;
    /// <summary>
    /// static ��� �������� ������� AddWhireCommand => ������
    /// </summary>
	/// <param name="p1">������ �������</param>
	/// <param name="p2">������� �������</param>
    static void AddComandW(Pin* p1,Pin* p2);
	/// <summary>
	/// ���� �������
	/// </summary>
	/// <returns></returns>
	QColor color() override;
};
#endif
