#pragma once
#ifndef ADDPINCOMAND_H
#define ADDPINCOMAND_H
#include <QUndoCommand>
class Port;
class Pin;
class AddComand;
/// <summary>
/// Класс наследник от QUndoCommand на добавление нового контакта в разъем
/// <para>
/// Класс "сам в себе", жрет ы конструкторе там же пушится в стэк....
/// </para>
/// </summary>
class AddPinComand  : public QUndoCommand
{
public:
	/// <summary>
	///  Сам в себе высерает себя же в стэк в котором лежит команда создания разъема p
	/// </summary>
	/// <param name="p">Разъем в который добовляем крнтакт</param>
	/// <param name="name">имя создоваемого контакта</param>
	/// <param name="rea">false если шаблон порта, true если порт на сцене </param>
	AddPinComand(Port*p,QString name="",bool rea=true);
	/// <summary>
	/// Деструктор
	/// </summary>
	~AddPinComand();
	/// <summary>
	/// Удаляет контакт 
	/// </summary>
	void undo() override;
	/// <summary>
	/// Создает контакт
	/// </summary>
	void redo() override;
	/// <summary>
	/// Имя контакта
	/// </summary>
	QString name = "";
	/// <summary>
	/// Созданный контакт для удаления в дальнейшем
	/// </summary>
	Pin* pn = nullptr;
	/// <summary>
	/// Команда создания разъема для вытягивания разъема так как он может быть перезаписан а команда останется
	/// </summary>
	AddComand* prt;
	bool real;
};
#endif
