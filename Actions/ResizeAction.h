#pragma once
#include "Action.h"
class ResizeAction :public Action
{
private:

public:
	ResizeAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#pragma once
