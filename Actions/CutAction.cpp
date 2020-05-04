#pragma once
#include<iostream>

#include"CutAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

CutAction::CutAction(ApplicationManager * pApp) :Action(pApp)
{
}
void CutAction::ReadActionParameters() {
	
}
void CutAction::Execute() {
	Output* pOut = pManager->GetOutput();
	CFigure* selected = pManager->GetSelected();
	if(selected==NULL)
		{
			pOut->PrintMessage("No selected figure");
			return;
	}
	if(pManager->getiscut()){
		pManager->Delete(pManager->GetClipBoard());
		pManager->GetClipBoard()->setdrcolor(pManager->getcolorb4());
		pManager->AddFigure(pManager->GetClipBoard());
	}
	pManager->setiscut(true);
	
		selected->SetSelected(false);
		pManager->setClipBoard(selected);

		pOut->PrintMessage("The selected figure is copied to the clipboard");

	pManager->setcolorb4(selected->getdrcolor());
	selected->ChngDrawClr(GREY);
	selected->ChngFillClr(GREY);
}