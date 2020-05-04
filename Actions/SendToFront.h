#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class SendToFront :public Action
{
	CFigure* SelectedFig;
public:

	SendToFront(ApplicationManager *pApp);
	virtual void ReadActionParameters();

	virtual void Execute();

}; 
