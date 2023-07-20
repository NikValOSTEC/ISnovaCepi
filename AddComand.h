#pragma once
#ifndef ADDCOMAND_H
#define ADDCOMAND_H
#include <QUndoCommand>
#include<QDebug>
#include<qgraphicsproxywidget.h>
class View;
class Port;

/// <summary>
/// ����� ��������� �� QUndoCommand �� ���������� ������ ������� �� �����
/// <para>
/// ����� "��� � ����", ���� � ������������ ��� �� ������� � ����....
/// </para>
/// </summary>
class AddComand  : public QUndoCommand
{
public:
	/// <summary>
	/// ����������� 
	/// <para>
	/// ��� � ���� �������� ���� �� � ���� �� <paramref name="v"/> � ��������� �� �����, �� view, Port
	/// </para>
	/// </summary>
	/// <param name="v">����������� � ������� ���������� ������ ����� � ������ Undo ����</param>
	/// <param name="x">���������� x ������� �� �����</param>
	/// <param name="y">���������� y ������� �� �����</param>
	/// <param name="name">��� ������</param>
	AddComand(View* v, int x, int y,QString name="");
	/// <summary>
	/// ����������
	/// </summary>
	~AddComand();
	/// <summary>
	/// ���������� ���������� � ���, � ������� ������
	/// </summary>
	void undo() override;
	/// <summary>
	/// ������� ������ � ���������� ��� ����������� �����������, � ���������� ��� ����������� ������ 
	/// </summary>
	void redo() override;
	/// <summary>
	/// ����������� ������
	/// </summary>
	Port* p;
	/// <summary>
	/// ����������
	/// </summary>
	int xx, yy;
	/// <summary>
	/// ����������� � ������� �������� �������
	/// </summary>
	View* v;
	/// <summary>
	/// ��� ������������ �����
	/// </summary>
	QString name;
};
#endif
