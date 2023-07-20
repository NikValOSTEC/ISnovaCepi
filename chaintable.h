#pragma once
#ifndef CHAINTABLE_H
#define CHAINTABLE_H
class View;
#include<qobject.h>
#include<qtablewidget.h>
#include<qinputdialog.h>
#include"qheaderview.h"
/// <summary>
/// Табличный вид цепей
/// </summary>
class ChainTable  : public QTableWidget
{
	Q_OBJECT

public:
	/// <summary>
	/// Конструктор
	/// </summary>
	ChainTable();
	/// <summary>
	/// Деструктор
	/// </summary>
	~ChainTable();
	/// <summary>
	/// Отображение в котором выводятся цепи  
	/// </summary>
	View* view=nullptr;
	/// <summary>
	/// Добовление порта в отображеение
	/// </summary>
	void AdddPortSL();
	/// <summary>
	/// Добовление Цепм в список и в отображение
	/// </summary>
	void AddChain();
public slots:
	/// <summary>
	/// Обновление таблицы исходя из отображения
	/// </summary>
	void UpdateTable();
	/// <summary>
	/// Пересчет цепей по обновлению в таблице
	/// </summary>
	/// <param name="row">строка</param>
	/// <param name="column">колонка</param>
	void CellChange(int row, int column);
	/// <summary>
	/// Оброботка клика на +
	/// </summary>
	/// <param name="row">строка</param>
	/// <param name="colum">колонка</param>
	void CellClck(int row, int colum);
protected:
	/// <summary>
	/// связка для обновлений то нужна то мешает тч перезапись
	/// </summary>
	QMetaObject::Connection m_connection;
};
#endif
