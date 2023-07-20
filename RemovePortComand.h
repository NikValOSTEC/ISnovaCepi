#pragma once
#ifndef REMOVECOMAND_H
#define REMOVECOMAND_H
#include<QUndoCommand>
class Port;
class AddComand;
class View;

/// <summary>
/// Undo Redo Удаление разъема
/// </summary>
class RemovePortComand  : public QUndoCommand
{
public:	/// <summary>
	/// создание команды в стэк
	/// </summary>
	/// <param name="p">удаляемый разъем</param>
	RemovePortComand(Port* p);
	/// <summary>
	/// Деструктор
	/// </summary>
	~RemovePortComand();
	/// <summary>
	/// Создает разъем снова и закладывает его в ту же команду создания для сохранения цепочки
	/// </summary>
	void undo() override;
	/// <summary>
	/// Удаляет разъем
	/// </summary>
	void redo() override;
	/// <summary>
	/// имя разъема
	/// </summary>
	QString name;
	/// <summary>
	/// Команда создания удаляемого разъема (для перезаписи при откате)
	/// </summary>
	AddComand* addcom;
	/// <summary>
	/// отображение в котором лежит разъем
	/// </summary>
	View* v;
	/// <summary>
	/// координаты разъема
	/// </summary>
	int xx, yy;
};
#endif
