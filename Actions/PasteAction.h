#pragma once
#include "Action.h"
class PasteAction :public Action
{
private:
	Point P;
public:
	PasteAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();

	virtual void Execute();
};