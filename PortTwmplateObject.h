#pragma once
#ifndef PORTTWMPLATEOBJECT_H
#define PORTTWMPLATEOBJECT_H
#include<qobject.h>
#include<qwidget.h>
#include"qpushbutton.h"
#include"qlineedit.h"
class PortTemplate;

/// <summary>
/// ������ ��� ������� �������
/// </summary>
class PortTwmplateObject  : public QWidget
{
	Q_OBJECT

public:
	/// <summary>
	/// ������ �������
	/// </summary>
	PortTemplate* templ;
	/// <summary>
	/// ������ ���������
	/// </summary>
	QPushButton* editpb;
	/// <summary>
	/// ������ ��������
	/// </summary>
	QPushButton* delpb;
	/// <summary>
	/// ������ �����
	/// </summary>
	QLineEdit* name;
	/// <summary>
	/// ������������� �� �����
	/// <para> 
	/// ��. https://doc.qt.io/qt-6/qgraphicsitem.html
	/// </para>
	/// </summary>
	void dragEnterEvent(QDragEnterEvent* event) override;
	/// <summary>
	/// ������������� �� �����
	/// <para> 
	/// ��. https://doc.qt.io/qt-6/qgraphicsitem.html
	/// </para>
	/// </summary>
	void dropEvent(QDropEvent* event) override;
	/// <summary>
	/// ������������� �� �����
	/// <para> 
	/// ��. https://doc.qt.io/qt-6/qgraphicsitem.html
	/// </para>
	/// </summary>
	void dragMoveEvent(QDragMoveEvent* event) override;
	/// <summary>
	/// ������������� �� �����
	/// <para> 
	/// ��. https://doc.qt.io/qt-6/qgraphicsitem.html
	/// </para>
	/// </summary>
	void mousePressEvent(QMouseEvent* event) override;

public slots:
	/// <summary>
	/// ���� �� ���������
	/// </summary>
	void editPush();
	/// <summary>
	/// ��������
	/// </summary>
	void delPush();
public:
	/// <summary>
	/// �����������
	/// </summary>
	PortTwmplateObject();
	/// <summary>
	/// ����������
	/// </summary>
	~PortTwmplateObject();

};
#endif
