#pragma once
#include<iostream>

#include "ResizeAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ResizeAction::ResizeAction(ApplicationManager * pApp) :Action(pApp)
{}


void ResizeAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//pIn->GetPointClicked(P1.x, P1.y);
	pOut->PrintMessage("You are using the Resize action");


	pOut->ClearStatusBar();
}

//Execute the action
void ResizeAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	//CFigure * mymade;
	CFigure* p=pManager->GetSelected();
	if(p==NULL) {
		pOut->PrintMessage("No selected figure");
		return;
	}
	double r = 1;
	pManager->GetResize(r);
	pManager->Delete(p);
	p->setresizingfactor(r);
	p->setpointsresized(pOut);
	//CFigure* resized=p->create();
	pManager->AddFigure(p);
	p->SetSelected(false);
	//if (mymade != NULL)
	//{
	//	pManager->SetunSelectedApp(mymade);
	//	//mymade->fillcolorsubsequentdrawings(c);
	//	mymade->ChngDrawClr(pManager->Getcolor(c));
	//	pManager->SetSelectedApp(mymade);

	cout << "test " << endl;
	//}
}