#pragma once
#ifndef ADDWHIRECOMMAND_H
#define ADDWHIRECOMAND_H
#include<QUndoCommand>
class AddPinComand;
class NewWhire;
/// <summary>
/// ����� ��������� �� QUndoCommand �� ���������� ������ ������� �� �����
/// <para>
/// ����� "��� � ����", ���� � ������������ ��� �� ������� � ����....
/// </para>
/// </summary>
class AddWhireCommand: public QUndoCommand
{
public:
	/// <summary>
	///  ��� � ���� �������� ���� �� � ���� �� �������� p11 � ��������� �� �����, �� view � ������� �������� p11 ������, 
	/// </summary>
	/// <param name="p11">������ ������� ����������� ��������</param>
	/// <param name="p22">������ ������� ����������� ��������</param>
	AddWhireCommand(AddPinComand* p11, AddPinComand* p22);
	/// <summary>
	/// ����������
	/// </summary>
	~AddWhireCommand();
	/// <summary>
	/// ������� ������ 
	/// </summary>
	void undo() override;
	/// <summary>
	/// ������� ������
	/// </summary>
	void redo() override;
	/// <summary>
	/// �������� ����������� ��������
	/// </summary>
	AddPinComand* p1, *p2;
	/// <summary>
	/// ��������� ������
	/// </summary>
	NewWhire* whire;
};
#endif
