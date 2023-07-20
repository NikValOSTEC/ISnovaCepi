#pragma once
#ifndef CHAINTABLE_H
#define CHAINTABLE_H
class View;
#include<qobject.h>
#include<qtablewidget.h>
#include<qinputdialog.h>
#include"qheaderview.h"
/// <summary>
/// ��������� ��� �����
/// </summary>
class ChainTable  : public QTableWidget
{
	Q_OBJECT

public:
	/// <summary>
	/// �����������
	/// </summary>
	ChainTable();
	/// <summary>
	/// ����������
	/// </summary>
	~ChainTable();
	/// <summary>
	/// ����������� � ������� ��������� ����  
	/// </summary>
	View* view=nullptr;
	/// <summary>
	/// ���������� ����� � ������������
	/// </summary>
	void AdddPortSL();
	/// <summary>
	/// ���������� ���� � ������ � � �����������
	/// </summary>
	void AddChain();
public slots:
	/// <summary>
	/// ���������� ������� ������ �� �����������
	/// </summary>
	void UpdateTable();
	/// <summary>
	/// �������� ����� �� ���������� � �������
	/// </summary>
	/// <param name="row">������</param>
	/// <param name="column">�������</param>
	void CellChange(int row, int column);
	/// <summary>
	/// ��������� ����� �� +
	/// </summary>
	/// <param name="row">������</param>
	/// <param name="colum">�������</param>
	void CellClck(int row, int colum);
protected:
	/// <summary>
	/// ������ ��� ���������� �� ����� �� ������ �� ����������
	/// </summary>
	QMetaObject::Connection m_connection;
};
#endif
