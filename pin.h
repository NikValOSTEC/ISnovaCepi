#pragma once
#ifndef PIN_H
#define PIN_H
#include<QThread>
#include"ui_pin.h"
#include<qgraphicsproxywidget.h>
#include<QColorDialog>
#include<QLineEdit>
class Port;
class NewPinWhire;
class AddPinComand;
class Chain;
class Dot;
namespace Ui {
class Pin;
}
/// <summary>
/// Контакт
/// </summary>
class Pin : public QLineEdit
{
    Q_OBJECT

public:
    /// <summary>
    /// Создает контакт
    /// </summary>
    /// <param name="port">Разъем в котором находится контакт</param>
    /// <param name="bl">Делать ли провод к контакту</param>
    /// <param name="parent"></param>
    explicit Pin(Port* port,bool bl=true,QLineEdit *parent = nullptr);
    /// <summary>
    /// Деструктор
    /// </summary>
    ~Pin();
    /// <summary>
    /// положение контакта по высоте в разъеме
    /// </summary>
    /// <returns></returns>
    int index();
    /// <summary>
    /// Имя контакта
    /// </summary>
    /// <returns></returns>
    const QString name();
    /// <summary>
    /// Установка имени контакта
    /// </summary>
    /// <param name="name"></param>
    void name(QString name);
public slots:
    /// <summary>
    /// Обновление
    /// </summary>
    void Update(bool dotupd);
signals:
    /// <summary>
    /// Сигнал обновления
    /// </summary>
    void updSignal(bool upddots);
public:
    /// <summary>
    /// вызов сигнала обновления
    /// </summary>
    /// <param name="dotold"></param>
    void EmitUpd(bool dotold=false);
    /// <summary>
    /// Возвращает провод от данного контакта
    /// </summary>
    /// <returns></returns>
    NewPinWhire* getpinWhire();
    /// <summary>
    /// Разъем в котором лежим контакт
    /// </summary>
    Port* parCon;
    /// <summary>
    /// Внешняя точка провода контакта
    /// </summary>
    /// <param name="recalc">пересчитывать ли провод (коллизии)</param>
    /// <returns>внешняя точка пина</returns>
    virtual Dot* dot(bool recalc = false);
    /// <summary>
    /// установка внешней точки провода
    /// </summary>
    /// <param name="d"></param>
    virtual void dot(Dot* d);
private:
    /// <summary>
    /// Перегрузка
    /// </summary>
    /// <param name="event"></param>
    void mousePressEvent(QMouseEvent* event) override;
    /// <summary>
    /// Перегрузка
    /// </summary>
    virtual void dragEnterEvent(QDragEnterEvent* event) override;
    /// <summary>
    /// Перегрузка
    /// </summary>
    virtual void dropEvent(QDropEvent* event) override;
    /// <summary>
    /// Перегрузка
    /// </summary>
    virtual void dragMoveEvent(QDragMoveEvent* event) override;
public:
    /// <summary>
    /// Внутренняя точка провода конткта
    /// </summary>
    /// <returns></returns>
    Dot* coredot();
    /// <summary>
    /// координата x контакта на сцене
    /// </summary>
    /// <returns></returns>
    qreal x();
    /// <summary>
    /// координата y контакта на сцене
    /// </summary>
    qreal y();
    /// <summary>
    /// Отображение провода контакта
    /// </summary>
    /// <param name="show"></param>
    void pinWhire(bool show=true);
    /// <summary>
    /// Пересчет расположения внутрнней точки провода
    /// </summary>
    /// <param name="upd"></param>
    void PinWUpd(bool upd = true);
    /// <summary>
    /// цепь к которой пренадлежит контакт
    /// </summary>
    Chain* chain;
    /// <summary>
    /// Команда добавления контакта Undo
    /// </summary>
    AddPinComand* command=nullptr;
protected:
    /// <summary>
    /// Контекстное меню для удаления... по правой кнопке мыши
    /// </summary>
    /// <returns></returns>
    virtual QMenu* ContextMenu();
    Ui::Pin *ui;
    /// <summary>
    /// Обновление при движении
    /// </summary>
    bool upd = false; 
public slots:
    /// <summary>
    /// удаление из цепи
    /// </summary>
    void RemoveFromChain();
    /// <summary>
    /// удаление
    /// </summary>
    void Remove();
protected slots:
    /// <summary>
    /// Демонстрация контекстного меню
    /// </summary>
    virtual void showContextMenu(const QPoint& pos);
    /// <summary>
    /// Вызов colorDialog для смены цвета цепи в которую входит контакт
    /// </summary>
    void ChangeColor();
private:
    bool updaterbl;
    /// <summary>
    /// Внешняя точка провода от контакта
    /// </summary>
    Dot* d;
    /// <summary>
    /// внутрянняя точка провода от контакта
    /// </summary>
    Dot* cored;
    /// <summary>
    /// Провод от контакта
    /// </summary>
    NewPinWhire* pinW;
    /// <summary>
    /// поток в котором лежит контакт
    /// </summary>
    QThread* thread;
    /// <summary>
    /// имя контакта
    /// </summary>
    QString _name;

};

#endif // PIN_H
