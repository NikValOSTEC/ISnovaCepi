#pragma once
#ifndef ADDCOMAND_H
#define ADDCOMAND_H
#include <QUndoCommand>
#include<QDebug>
#include<qgraphicsproxywidget.h>
class View;
class Port;

/// <summary>
/// Класс наследник от QUndoCommand на добавление нового разъема на сцену
/// <para>
/// Класс "сам в себе", жрет ы конструкторе там же пушится в стэк....
/// </para>
/// </summary>
class AddComand  : public QUndoCommand
{
public:
	/// <summary>
	/// Конструктор 
	/// <para>
	/// Сам в себе высерает себя же в стэк из <paramref name="v"/> и добавляет на сцену, из view, Port
	/// </para>
	/// </summary>
	/// <param name="v">Отображение в котором нахоодится нужная сцена и нужный Undo стэк</param>
	/// <param name="x">Координата x разъема на сцене</param>
	/// <param name="y">Координата y разъема на сцене</param>
	/// <param name="name">Имя раъема</param>
	AddComand(View* v, int x, int y,QString name="");
	/// <summary>
	/// Деструктор
	/// </summary>
	~AddComand();
	/// <summary>
	/// Запоминает координаты и имя, и удаляет разъем
	/// </summary>
	void undo() override;
	/// <summary>
	/// Создает разъем в переданных или запомненных координатах, с переданным или запомненным именем 
	/// </summary>
	void redo() override;
	/// <summary>
	/// Создаваемый разъем
	/// </summary>
	Port* p;
	/// <summary>
	/// Координаты
	/// </summary>
	int xx, yy;
	/// <summary>
	/// Отображение в котором работает команда
	/// </summary>
	View* v;
	/// <summary>
	/// Имя создоваемого порта
	/// </summary>
	QString name;
};
#endif
