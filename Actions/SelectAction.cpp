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
	pOut->PrintMessage("You are using the select action" );
	pIn->GetPointClicked(P1.x, P1.y);
	while (P1.y < UI.StatusBarHeight || P1.y > UI.height - UI.StatusBarHeight)
	{
		pOut->PrintMessage("Error! select inside the drawing area.");
		pIn->GetPointClicked(P1.x, P1.y);
	}

	
	
	pOut->ClearStatusBar();
}


//Execute the action
void SelectAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	//This action needs to read some parameters first
	ReadActionParameters();

	CFigure * mymade;
	//CFigure * mymadeunselect;
	mymade = pManager->GetFigure(P1.x, P1.y);
	if (mymade != NULL)
	{
		cout << "it is find " << endl;
		if (mymade->IsSelected() == false)
		{
			//mymade->SetSelected(true);
			pManager->SetSelectedApp(mymade);
			mymade->printinfo( pOut);
			
		}
		
		else
		{
			//mymade->SetSelected(false);
			pManager->SetunSelectedApp(mymade);
			pOut->PrintMessage("You have unselected a figure");

		}
		
	}
	else
	{
		cout << "not found " << endl; 
		mymade = pManager->GetSelected();
		if (mymade != NULL)
		{
			pManager->SetunSelectedApp(mymade);
			pOut->PrintMessage("U have used the unselect Action ");
		}
		//else
			//pManager->SetunSelectedApp(mymadeunselect);
	}

}


