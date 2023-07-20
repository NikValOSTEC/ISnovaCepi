#pragma once
#ifndef WHIREREMOVECOMAND_H
#define WHIREREMOVECOMAND_H
#include<QUndoCommand>
class NewWhire;
class AddPinComand;
class AddWhireCommand;
/// <summary>
/// ������� �������� ������� Undo Redo
/// </summary>
class WhireRemoveComand  : public QUndoCommand
{
public:
	/// <summary>
	/// �������� ������� �� �������� �������
	/// </summary>
	/// <param name="w">��������� ������</param>
	WhireRemoveComand(NewWhire* w);
	/// <summary>
	/// ����������
	/// </summary>
	~WhireRemoveComand();
	/// <summary>
	/// ����������� ������ ����� p1 � p2 � ������ � ������� wc
	/// </summary>
	void undo() override;
	/// <summary>
	/// �������� ������
	/// </summary>
	void redo() override;
	/// <summary>
	/// �������� p1 � p2
	/// </summary>
	AddPinComand* p1, * p2;
	/// <summary>
	/// ������� ���������� ���������� ������
	/// </summary>
	AddWhireCommand* wc;
};
#endif
