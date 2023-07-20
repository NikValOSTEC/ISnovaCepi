#pragma once
#ifndef ADDPINCOMAND_H
#define ADDPINCOMAND_H
#include <QUndoCommand>
class Port;
class Pin;
class AddComand;
/// <summary>
/// ����� ��������� �� QUndoCommand �� ���������� ������ �������� � ������
/// <para>
/// ����� "��� � ����", ���� � ������������ ��� �� ������� � ����....
/// </para>
/// </summary>
class AddPinComand  : public QUndoCommand
{
public:
	/// <summary>
	///  ��� � ���� �������� ���� �� � ���� � ������� ����� ������� �������� ������� p
	/// </summary>
	/// <param name="p">������ � ������� ��������� �������</param>
	/// <param name="name">��� ������������ ��������</param>
	/// <param name="rea">false ���� ������ �����, true ���� ���� �� ����� </param>
	AddPinComand(Port*p,QString name="",bool rea=true);
	/// <summary>
	/// ����������
	/// </summary>
	~AddPinComand();
	/// <summary>
	/// ������� ������� 
	/// </summary>
	void undo() override;
	/// <summary>
	/// ������� �������
	/// </summary>
	void redo() override;
	/// <summary>
	/// ��� ��������
	/// </summary>
	QString name = "";
	/// <summary>
	/// ��������� ������� ��� �������� � ����������
	/// </summary>
	Pin* pn = nullptr;
	/// <summary>
	/// ������� �������� ������� ��� ����������� ������� ��� ��� �� ����� ���� ����������� � ������� ���������
	/// </summary>
	AddComand* prt;
	bool real;
};
#endif
