#pragma once
#include "Action.h"
class Fillcolor :public Action
{
private:
	//Point P1;
	GfxInfo selectGfxInfo;
	//ActionType ActType;

public:
	Fillcolor(ApplicationManager *pApp);	//Reads rectangle parameters
	virtual void ReadActionParameters();
	//Add rectangle to the ApplicationManager
	virtual void Execute();
};
#pragma once
