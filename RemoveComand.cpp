#include "RemoveComand.h"

RemovePortComand::RemovePortComand(Port* port )
{
	delete port;
}

RemovePortComand::~RemovePortComand()
{}

void RemovePortComand::undo()
{
}

void RemovePortComand::redo()
{
}
