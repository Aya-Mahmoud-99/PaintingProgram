#pragma once
#include "Action.h"

class Exit :public Action
{
public:
	Exit(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	//Execute action (Exit action)
	virtual void Execute();


};
#pragma once
