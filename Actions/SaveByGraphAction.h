#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class SaveByGraphAction :public Action
{
	string DrawColor;
	string FillColor;
	string fileName;
public:

	SaveByGraphAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();

	virtual void Execute();
	string DrawColorToString();
	string FillColorToString();
};
