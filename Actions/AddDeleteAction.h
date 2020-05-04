#pragma once
#pragma once
#include "Action.h"
class AddDeleteAction :public Action
{
private:
	Point P1; // point of select
	GfxInfo selectGfxInfo;
public:
	AddDeleteAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
};
