#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class SaveByTypeAction :public Action
{
	string DrawColor;
	string FillColor;
	string fileName;
public:

	SaveByTypeAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();

	virtual void Execute();
	string DrawColorToString();
	string FillColorToString();
};
