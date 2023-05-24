#include<QUndoCommand>
class AddPinComand;
#include"AddPinComand.h"
class NewWhire;
#include"NewWhire.h"
class AddWhireCommand  : public QUndoCommand
{
public:
	AddWhireCommand(AddPinComand* p11, AddPinComand* p22);
	~AddWhireCommand();
	void undo() override;
	void redo() override;
	AddPinComand* p1, *p2;
	NewWhire* whire;
};
