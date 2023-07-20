#pragma once
#ifndef PORTTEMPLATE_H
#define PORTTEMPLATE_H
#include"qobject.h"
#include"ui_port.h"
#include <qopenglfunctions.h>
#include"port.h"
class PortTwmplateObject;
class SaveTemplates;
class Pin;

namespace Ui {
	class Port;
}

/// <summary>
/// Шаблон Разъема; перегрузка разъема ( убрано перемещение итд)
/// </summary>
class PortTemplate  : public Port
{
	Q_OBJECT

public:
	/// <summary>
	/// Новый Шаблон hfp]tvf
	/// </summary>
	/// <param name="o">Объект для Drag and Drop</param>
	PortTemplate(PortTwmplateObject* o);
	/// <summary>
	/// Добавление контакта (шаблона контакта)
	/// </summary>
	/// <param name="name"></param>
	/// <param name="index"></param>
	/// <returns>Добавленный контакт</returns>
	Pin* addPinn(QString name = "", int index = -1);
	/// <summary>
	/// Деструктор
	/// </summary>
	~PortTemplate();
private:
	/// <summary>
	/// Объект для Drag and Drop
	/// </summary>
	PortTwmplateObject* object;
private slots:
	/// <summary>
	/// Добавление контакта
	/// </summary>
	Pin* addPinSl(QString name = "");
	/// <summary>
	/// Удаление Шаблона
	/// </summary>
	void RemoveSL();
	/// <summary>
	/// Закрытие окна редактирования шаблона (сохранение)
	/// </summary>
	/// <param name="event"></param>
	void closeEvent(QCloseEvent* event) override;
    /// <summary>
    /// Контекстное меню
    /// </summary>
    /// <returns></returns>
    virtual QMenu* ContextMenu();
};
#endif
