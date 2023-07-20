#pragma once
#ifndef REMOVEPINCOMMAND_H
#define REMOVEPINCOMMAND_H
#include<QUndoCommand>
class Pin;
class Port;
class AddPinComand;
/// <summary>
/// Undo Redo �������� ��������
/// </summary>
class RemovePinCommand  : public QUndoCommand
{

public:
	/// <summary>
	/// �������� ������� � ����
	/// </summary>
	/// <param name="p">��������� �������</param>
	RemovePinCommand(Pin*p);
	/// <summary>
	/// ����������
	/// </summary>
	~RemovePinCommand();
	/// <summary>
	/// ������� ������� ����� � ����������� ��� � �� �� ������� �������� ��� ���������� �������
	/// </summary>
	void undo() override;
	/// <summary>
	/// ������� ������� ��������� ��� ������ � ������� � ���
	/// </summary>
	void redo() override;
	/// <summary>
	/// ������� ���������� �������� � �������
	/// </summary>
	int pos = 0;
	/// <summary>
	/// ��� ���������� ��������
	/// </summary>
	QString name = "";
	/// <summary>
	/// ������� �������� ���������� �������� (��� ���������� ��� ������
	/// </summary>
	AddPinComand* pinc;
	/// <summary>
	/// ������ � ������� ��������� �������
	/// </summary>
	Port* prt;
	/// <summary>
	/// ��������� �������
	/// </summary>
	Pin* pin;

};
#endif
