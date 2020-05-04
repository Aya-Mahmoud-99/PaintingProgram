#pragma once
#include<iostream>

#include"AddDeleteAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddDeleteAction::AddDeleteAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddDeleteAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();	
	


	pOut->ClearStatusBar();
}

//Execute the action
void AddDeleteAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	//This action needs to read some parameters first
	ReadActionParameters();
	CFigure * mymade = pManager->GetSelected();
	if (mymade != NULL)
	{
		pManager->Delete(mymade);
		pOut->PrintMessage("U have deleted a figure");
	}
	else
		pOut->PrintMessage("there is no figure selected to be deleted");
	
}