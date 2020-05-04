#pragma once
#include<iostream>

#include"Changecolor.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
Changecolor::Changecolor(ApplicationManager * pApp) :Action(pApp)
{}


void Changecolor::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//pIn->GetPointClicked(P1.x, P1.y);
	pOut->PrintMessage("You are using the Changecolor action");

	pOut->ClearStatusBar();
}

//Execute the action
void Changecolor::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	color c;
	CFigure * mymade;
	mymade = pManager->GetSelected();
	if (mymade != NULL)
	{
		c = mymade->getdrcolormymade();
		//According to Action Type, create the corresponding action object
		pManager->GetColor(c);
		// dh hags :D 
	}

	Output* pOut = pManager->GetOutput();


	if (mymade != NULL)
	{
		mymade->ChngDrawClr(c);
		mymade->changecolorsubsequentdrawings(c);
		//mymade->ChngDrawClr(pManager->Getcolor(c));
		mymade->SetSelected(false);
		pManager->SetunSelectedApp(mymade);

		pOut->PrintMessage("You have changed the color");
		cout << "Change color is called " << endl;
	}
	else
	{
		pOut->PrintMessage("You have to select figure first");
	}

}




