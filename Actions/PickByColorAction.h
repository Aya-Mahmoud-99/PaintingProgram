#pragma once
#include "Action.h"
#include <Math.h>
//#include "..\Figures\CFigure.h"
class PickByColorAction :public Action
{
	int correct = 0;
	int wrong = 0;
	Point P1;
	int colorcount;
//	Point P1;
public:
//
	PickByColorAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();

	virtual void Execute();
	void RandomColor(string &shapecolor);
};
