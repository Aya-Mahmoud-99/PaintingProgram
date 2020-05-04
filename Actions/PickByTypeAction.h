#pragma once
#include "Action.h"
#include <Math.h>
//#include <typeinfo>
#include "..\Figures\CFigure.h"
class PickByTypeAction :public Action
{
	int correct = 0;
	int wrong = 0;
	string shapetype;
	Point P1;
public:

	PickByTypeAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();

	virtual void Execute();
	void RandomShape(string &shapetype);
};
