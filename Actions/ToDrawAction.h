#pragma once
#include "Action.h"
#include <fstream>

class ToDrawAction :public Action
{
	int FigCount;
	string DrawColor;
	string FillColor;
	ofstream SaveFile;
	//	Point P1;
public:
	//
	ToDrawAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();

	virtual void Execute();
};
