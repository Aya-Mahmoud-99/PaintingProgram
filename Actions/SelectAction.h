#pragma once
#include "Action.h"

class SelectAction :public Action
{
private:
	Point P1; // point of select
	GfxInfo selectGfxInfo;
public:
	SelectAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
};
