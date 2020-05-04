#pragma once
#include<iostream>

#include"SelectAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager * pApp) :Action(pApp)
{}

void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	// point P1
	pIn->GetPointClicked(P1.x, P1.y);
	while (P1.y < UI.StatusBarHeight || P1.y > UI.height - UI.StatusBarHeight)
	{
		pOut->PrintMessage("Error! Draw inside the drawing area.");
		pIn->GetPointClicked(P1.x, P1.y);
	}



	pOut->ClearStatusBar();
}


//Execute the action
void SelectAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	CFigure * mymade;
	mymade = pManager->GetSelected();


}




