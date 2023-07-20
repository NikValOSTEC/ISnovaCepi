#ifndef NEWWHIRE_H
#define NEWWHIRE_H
#pragma once
#include"CustomColliderLineRecoursive.h"
class Pin;
class AddWhireCommand;
class Chain;
/// <summary>
/// Вертикальный провод соеденяющий 2 контакта 
/// 
/// <para>
/// соеденяет 2 внешние точки NewPinWhire 
/// </para>
/// </summary>
class NewWhire  : public CustomColliderLineRecoursive
{
	//Q_OBJECT
public:
	/// <summary>
	/// Контакты соедененные проводом
	/// </summary>
	Pin *p1 = nullptr, *p2 = nullptr;
	/// <summary>
	/// Цепь в которую входит данный провод и соедененные им контакты
	/// </summary>
	Chain* chain = nullptr;
	/// <summary>
	/// Добавляет провод на сцену
	/// </summary>
	/// <param name="pp1">Первый Контакт</param>
	/// <param name="pp2">Второрй Контакт</param>
	/// <param name="comm">Команда Undo в которой создается провод (передается из com как this)</param>
	NewWhire(Pin*pp1,Pin*pp2,AddWhireCommand* comm);
	/// <summary>
	/// Деструктор
	/// </summary>
	~NewWhire();
	/// <summary>
	/// Команда Undo создания провода
	/// </summary>
	AddWhireCommand* command;
    /// <summary>
    /// static для создания команды AddWhireCommand => провод
    /// </summary>
	/// <param name="p1">Первый Контакт</param>
	/// <param name="p2">Второрй Контакт</param>
    static void AddComandW(Pin* p1,Pin* p2);
	/// <summary>
	/// Цвет провода
	/// </summary>
	/// <returns></returns>
	QColor color() override;
};
#endif
