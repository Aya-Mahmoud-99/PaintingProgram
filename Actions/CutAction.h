#pragma once
#include"Action.h"
class CutAction :public Action
{
private:
public:
	CutAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();

	virtual void Execute();
};