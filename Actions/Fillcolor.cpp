#pragma once
#include<iostream>

#include "Fillcolor.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
Fillcolor::Fillcolor(ApplicationManager * pApp) :Action(pApp)
{}


void Fillcolor::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("You are using the Fill Color action");

	pOut->ClearStatusBar();
}

//Execute the action
void Fillcolor::Execute()
{
	Output* pOut = pManager->GetOutput();
	//This action needs to read some parameters first
	ReadActionParameters();
	CFigure * mymade;
	color c = RED;
	//According to Action Type, create the corresponding action object
	pManager->GetColor(c); 
	 // dh hags :D 
	mymade = pManager->GetSelected();

	

	if (mymade != NULL)
	{
		mymade->ChngFillClr(c);
		mymade->fillcolorsubsequentdrawings(c);
		//mymade->ChngDrawClr(pManager->Getcolor(c));
		mymade->SetSelected(false);
		pManager->SetunSelectedApp(mymade);
		cout << "Change color is called " << endl;
		pOut->PrintMessage("You have filled a shape with Color ");
	}
	else
	{
		pOut->PrintMessage("You have to select figure first");
	}
}




