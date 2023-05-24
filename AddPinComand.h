class Port;
#include"port.h"
class Pin;
#include"pin.h"
#include<QUndoCommand>
#include<QString>
class AddComand;
#include"AddComand.h"

class AddPinComand  : public QUndoCommand
{
public:
	AddPinComand(Port*p,QString name="");
	~AddPinComand();
	void undo() override;
	void redo() override;
	QString name = "";
	Pin* pn = nullptr;
	AddComand* prt;
};
