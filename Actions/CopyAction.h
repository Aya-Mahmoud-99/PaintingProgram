#pragma once
#include"Action.h"
class CopyAction :public Action
{
private:
public:
	CopyAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();

	virtual void Execute();
};