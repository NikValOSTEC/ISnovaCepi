#pragma once
#ifndef PORT_H
#define PORT_H
#include"ui_port.h"
#include"qobject.h"
#include<QMenu>
#include <QSpacerItem>
#include<qwidget.h>
class AddComand;
class Pin;
class ProxyRectPort;
namespace Ui {
class Port;
}

/// <summary>
/// Разъем на сцене
/// <para>
/// Вкладывается в прокси 
/// </para>
/// </summary>
class Port : public QWidget
{
    Q_OBJECT

public:
    /// <summary>
    /// Координата x на сцене
    /// </summary>
    /// <returns></returns>
    qreal x();
    /// <summary>
    /// Координата y на сцене
    /// </summary>
    /// <returns></returns>
    qreal y();
    /// <summary>
    /// Создает разъем 
    /// </summary>
    /// <param name="com">Undo команда в которой созданданный разъем</param>
    /// <param name="parent"></param>
    explicit Port(AddComand* com, QWidget *parent = nullptr);
    /// <summary>
    /// Создает разъем
    /// </summary>
    Port();
    /// <summary>
    /// Деструктор
    /// </summary>
    virtual ~Port();
    /// <summary>
    /// Имя разъема
    /// </summary>
    /// <returns></returns>
    QString name();
    /// <summary>
    /// Установка имени разъема
    /// </summary>
    /// <param name="str"></param>
    void name(QString str);
    /// <summary>
    /// Статический вектор для доступа ко всем разъемам из вне
    /// </summary>
    static QVector<Port*> portsVector;
    /// <summary>
    /// Список всех контактов разъема
    /// </summary>
    /// <returns></returns>
    QVector<Pin*>pins();
    /// <summary>
    /// Команда Undo по которой создан данный разъем
    /// </summary>
    AddComand* adcom;
    /// <summary>
    /// Удаление разъема
    /// </summary>
    void Remove();
    /// <summary>
    /// Добавление нового контакта
    /// </summary>
    /// <param name="name">имя нового контакта</param>
    /// <param name="index">место в списке контактов в разъеме</param>
    /// <param name="bl">выравнивание в высоту по клеточкам</param>
    /// <returns>Созданный контакт</returns>
    virtual Pin* addPin(QString name = "", int index = -1,bool bl=true);

private slots:
    /// <summary>
    /// Демонстрация контекстного меню
    /// </summary>
    void showContextMenu(const QPoint& pos);
    void on_pushButton_clicked();
    /// <summary>
    /// Слот на удаление
    /// </summary>
    void RemoveSL();
public slots:
    /// <summary>
    /// Добавление контакта вниз
    /// </summary>
    /// <param name="name">имя нового контакта</param>
    /// <returns>Созданный контакт</returns>
    Pin* addPinSl(QString name = "");
    /// <summary>
    /// Пересчет позиции и проводов
    /// </summary>
    void Update(bool updF=false);
    /// <summary>
    /// Прокси в который вложен разъем
    /// </summary>
    /// <returns></returns>
    ProxyRectPort* proxy();
    /// <summary>
    /// Передача прокси в который вкладывается разъем
    /// </summary>
    /// <param name="prox"></param>
    void proxy(ProxyRectPort*prox);


protected:
    Ui::Port *ui;
    /// <summary>
    /// Контекстное меню. Удаление; добавление контакта...
    /// </summary>
    /// <returns></returns>
    virtual QMenu* ContextMenu();
    /// <summary>
    /// прокси в который вложен разъем
    /// </summary>
    ProxyRectPort* _proxy;
    /// <summary>
    /// смещение для выравнивания контактов
    /// </summary>
    QSpacerItem* spacer;
};

#endif // PORT_H
