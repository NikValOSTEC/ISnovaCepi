#pragma once
#ifndef PORTTWMPLATEOBJECT_H
#define PORTTWMPLATEOBJECT_H
#include<qobject.h>
#include<qwidget.h>
#include"qpushbutton.h"
#include"qlineedit.h"
class PortTemplate;

/// <summary>
/// Объект для шаблона разъема
/// </summary>
class PortTwmplateObject  : public QWidget
{
	Q_OBJECT

public:
	/// <summary>
	/// Шаблон разъема
	/// </summary>
	PortTemplate* templ;
	/// <summary>
	/// кнопка изменения
	/// </summary>
	QPushButton* editpb;
	/// <summary>
	/// кнопка удаления
	/// </summary>
	QPushButton* delpb;
	/// <summary>
	/// строка имени
	/// </summary>
	QLineEdit* name;
	/// <summary>
	/// Перетягивание на сцену
	/// <para> 
	/// см. https://doc.qt.io/qt-6/qgraphicsitem.html
	/// </para>
	/// </summary>
	void dragEnterEvent(QDragEnterEvent* event) override;
	/// <summary>
	/// Перетягивание на сцену
	/// <para> 
	/// см. https://doc.qt.io/qt-6/qgraphicsitem.html
	/// </para>
	/// </summary>
	void dropEvent(QDropEvent* event) override;
	/// <summary>
	/// Перетягивание на сцену
	/// <para> 
	/// см. https://doc.qt.io/qt-6/qgraphicsitem.html
	/// </para>
	/// </summary>
	void dragMoveEvent(QDragMoveEvent* event) override;
	/// <summary>
	/// Перетягивание на сцену
	/// <para> 
	/// см. https://doc.qt.io/qt-6/qgraphicsitem.html
	/// </para>
	/// </summary>
	void mousePressEvent(QMouseEvent* event) override;

public slots:
	/// <summary>
	/// слот на изменение
	/// </summary>
	void editPush();
	/// <summary>
	/// удаление
	/// </summary>
	void delPush();
public:
	/// <summary>
	/// конструктор
	/// </summary>
	PortTwmplateObject();
	/// <summary>
	/// деструктор
	/// </summary>
	~PortTwmplateObject();

};
#endif
