#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class SendToBack :public Action
{
	CFigure* SelectedFig;
public:

	SendToBack(ApplicationManager *pApp);
	virtual void ReadActionParameters();

	virtual void Execute();

};