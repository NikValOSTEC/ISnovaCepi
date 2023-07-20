#pragma once
#include<qobject.h>
#include"qcolor.h"
class Pin;
#ifndef CHAIN_H
#define CHAIN_H
/// <summary>
/// Класс Цепи
/// <param>
/// Содержит соедененные в цепь контакты
/// </param>
/// </summary>
class Chain :public QObject
{
    Q_OBJECT
public:
    /// <summary>
    /// Новая цепь при соединении 2 контактов без цепей
    /// <para>
    /// Сам себя пишет в статический вектор chains
    /// </para>
    /// </summary>
    Chain();
    /// <summary>
    /// Деструктоор
    /// </summary>
    ~Chain();
    /// <summary>
    /// Записывает контакт в цепь при соединении его с контактом входящим в данную цепь
    /// </summary>
    /// <param name="p">Контакт</param>
    void AddPin(Pin* p);
    /// <summary>
    /// Удаляет контакт из цепи
    /// </summary>
    /// <param name="p">Удаляемый контакт</param>
    void RemovePin(Pin* p);
    /// <summary>
    /// статический вектор содержащий указатели на все цепи для получения ВСЕХ цепей из вне
    /// </summary>
    static QVector<Chain*> chains;
    /// <summary>
    /// Контакты входящие в цепь
    /// </summary>
    QVector<Pin*> pins;
    /// <summary>
    /// Соединение данной цепи и chain в одну
    /// </summary>
    /// <param name="chain"></param>
    void moveToChain(Chain* chain); 
    /// <summary>
    /// Пересчет соединений >2 линий в  1 точке, в цепи
    /// </summary>
    void Dots();
    /// <summary>
    /// Цвет проводов в цепи
    /// </summary>
    QColor color;
};
#endif
