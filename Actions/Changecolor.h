#pragma once
#include "Action.h"
class Changecolor :public Action
{
private:
	//Point P1;
	GfxInfo selectGfxInfo;
	//ActionType ActType;
	
public:
	Changecolor(ApplicationManager *pApp);	//Reads rectangle parameters
	virtual void ReadActionParameters();
	//Add rectangle to the ApplicationManager
	virtual void Execute();
};
