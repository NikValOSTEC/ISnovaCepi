#pragma once
#ifndef PINTEMPLATE_H
#define PINTEMPLATE_H
#include"pin.h"
class Port;
#include<qobject.h>
/// <summary>
/// Контакт из шаблонов (библиотеки) 
/// <para>
/// отключены провода итд
/// </para>
/// </summary>
class PinTemplate  : public Pin
{
	Q_OBJECT

public:
	/// <summary>
	/// Конструктор Pin
	/// </summary>
	/// <param name="p">разъем в котором лежит контакт (в среднем шаблонный разъем)</param>
	PinTemplate(Port* p);
    /// <summary>
    /// отключение перемещение итд
    /// </summary>
    /// <param name="event"></param>
    virtual void dragEnterEvent(QDragEnterEvent* event) override;
    /// <summary>
    /// отключение перемещение итд
    /// </summary>
    virtual void dropEvent(QDropEvent* event) override;
    /// <summary>
    /// отключение перемещение итд
    /// </summary>
    virtual void dragMoveEvent(QDragMoveEvent* event) override;
    /// <summary>
    /// Деструктор
    /// </summary>
    ~PinTemplate();
};
#endif
