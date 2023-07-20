#pragma once
#ifndef REMOVECOMAND_H
#define REMOVECOMAND_H
#include<QUndoCommand>
class Port;
class AddComand;
class View;

/// <summary>
/// Undo Redo �������� �������
/// </summary>
class RemovePortComand  : public QUndoCommand
{
public:	/// <summary>
	/// �������� ������� � ����
	/// </summary>
	/// <param name="p">��������� ������</param>
	RemovePortComand(Port* p);
	/// <summary>
	/// ����������
	/// </summary>
	~RemovePortComand();
	/// <summary>
	/// ������� ������ ����� � ����������� ��� � �� �� ������� �������� ��� ���������� �������
	/// </summary>
	void undo() override;
	/// <summary>
	/// ������� ������
	/// </summary>
	void redo() override;
	/// <summary>
	/// ��� �������
	/// </summary>
	QString name;
	/// <summary>
	/// ������� �������� ���������� ������� (��� ���������� ��� ������)
	/// </summary>
	AddComand* addcom;
	/// <summary>
	/// ����������� � ������� ����� ������
	/// </summary>
	View* v;
	/// <summary>
	/// ���������� �������
	/// </summary>
	int xx, yy;
};
#endif
