#pragma once
#include <fstream>
#include "Action.h"

class ToPlayAction :public Action
{
	string DrawColor;
	string FillColor;
	ofstream SaveFile;
	//	Point P1;
public:
	//
	ToPlayAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();

	virtual void Execute();

	string DrawColorToString();
	string FillColorToString();
};
