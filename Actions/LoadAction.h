#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class LoadAction :public Action
{
	string name;
	string DrawColor;
	string FillColor;
	int FigCount;
protected:
	string fileName;
public:
	LoadAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
