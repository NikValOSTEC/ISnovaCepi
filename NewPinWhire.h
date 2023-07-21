#pragma once
#ifndef NEWPINWHIRE_H
#define NEWPINWHIRE_H
#include<qthread.h>
#include<qobject.h>
class CustomColliderLineRecoursive;
#include"CustomColliderLineRecoursive.h"
class Pin;
/// <summary>
/// Горизонтальный провод идущий от контакта
/// <para>
/// Всегда один у каждого контакта
/// </para>
/// </summary>
class NewPinWhire  : public CustomColliderLineRecoursive
{
	Q_OBJECT
public:
	/// <summary>
	/// Конструктор 
	/// <para>
	/// Жрет контакт и поток в котором лежит этот контакт 
	/// </para>
	/// <para>
	/// По идее таки пошустрее в несколько потоков
	/// </para>
	/// </summary>
	/// <param name="p">Контакт к которому приложен провод</param>
	/// <param name="th">Поток в который он перемещен</param>
	NewPinWhire(Pin* p, QThread* th);
	/// <summary>
	/// Деструктор
	/// </summary>
	~NewPinWhire();
	/// <summary>
	/// наличие других связей
	/// </summary>
	/// <returns> true - есть; false - нет</returns>
	bool hasConection();
	/// <summary>
	/// Цвет провода
	/// </summary>
	/// <returns></returns>
	/// 
	


	/// <summary>
	/// Очистка дочерних линий ( выравнивание )
	/// </summary>
	virtual void ClearInside();


	QColor color() override;
private:
	/// <summary>
	/// Контак к которому идет провод
	/// </summary>
	Pin* pin;
};
#endif
