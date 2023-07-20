#pragma once
#ifndef ADDWHIRECOMMAND_H
#define ADDWHIRECOMAND_H
#include<QUndoCommand>
class AddPinComand;
class NewWhire;
/// <summary>
/// Класс наследник от QUndoCommand на добавление нового разъема на сцену
/// <para>
/// Класс "сам в себе", жрет ы конструкторе там же пушится в стэк....
/// </para>
/// </summary>
class AddWhireCommand: public QUndoCommand
{
public:
	/// <summary>
	///  Сам в себе высерает себя же в стэк из контакта p11 и добавляет на сцену, из view в разъеме контакта p11 провод, 
	/// </summary>
	/// <param name="p11">Первый контакт соедененный проводом</param>
	/// <param name="p22">Второй контакт соедененный проводом</param>
	AddWhireCommand(AddPinComand* p11, AddPinComand* p22);
	/// <summary>
	/// Деструктор
	/// </summary>
	~AddWhireCommand();
	/// <summary>
	/// Удаляет провод 
	/// </summary>
	void undo() override;
	/// <summary>
	/// Создает провод
	/// </summary>
	void redo() override;
	/// <summary>
	/// Контакты соедененные проводом
	/// </summary>
	AddPinComand* p1, *p2;
	/// <summary>
	/// Созданный провод
	/// </summary>
	NewWhire* whire;
};
#endif
