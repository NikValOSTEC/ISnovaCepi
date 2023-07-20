#pragma once
#ifndef REMOVEPINCOMMAND_H
#define REMOVEPINCOMMAND_H
#include<QUndoCommand>
class Pin;
class Port;
class AddPinComand;
/// <summary>
/// Undo Redo Удаление контакта
/// </summary>
class RemovePinCommand  : public QUndoCommand
{

public:
	/// <summary>
	/// создание команды в стэк
	/// </summary>
	/// <param name="p">удаляемый контакт</param>
	RemovePinCommand(Pin*p);
	/// <summary>
	/// Деструктор
	/// </summary>
	~RemovePinCommand();
	/// <summary>
	/// Создает контакт снова и закладывает его в ту же команду создания для сохранения цепочки
	/// </summary>
	void undo() override;
	/// <summary>
	/// Удаляет контакт запоминая его разъем и позицию в нем
	/// </summary>
	void redo() override;
	/// <summary>
	/// позиция удаляемого контакта в разъеме
	/// </summary>
	int pos = 0;
	/// <summary>
	/// имя удаляемого контакта
	/// </summary>
	QString name = "";
	/// <summary>
	/// Команда создания удаляемого контакта (для перезаписи при откате
	/// </summary>
	AddPinComand* pinc;
	/// <summary>
	/// Разъем в котором находится контакт
	/// </summary>
	Port* prt;
	/// <summary>
	/// Удаляемый контакт
	/// </summary>
	Pin* pin;

};
#endif
