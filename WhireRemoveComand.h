#pragma once
#ifndef WHIREREMOVECOMAND_H
#define WHIREREMOVECOMAND_H
#include<QUndoCommand>
class NewWhire;
class AddPinComand;
class AddWhireCommand;
/// <summary>
///  оманда удалени€ провода Undo Redo
/// </summary>
class WhireRemoveComand  : public QUndoCommand
{
public:
	/// <summary>
	/// —оздание команды на удаление провода
	/// </summary>
	/// <param name="w">удал€емый провод</param>
	WhireRemoveComand(NewWhire* w);
	/// <summary>
	/// ƒеструктор
	/// </summary>
	~WhireRemoveComand();
	/// <summary>
	/// возвращение кабел€ между p1 и p2 и запись в команду wc
	/// </summary>
	void undo() override;
	/// <summary>
	/// ”даление кабел€
	/// </summary>
	void redo() override;
	/// <summary>
	/// контакты p1 и p2
	/// </summary>
	AddPinComand* p1, * p2;
	/// <summary>
	///  оманда добовлени€ удал€емого кабел€
	/// </summary>
	AddWhireCommand* wc;
};
#endif
