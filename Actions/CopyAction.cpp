#pragma once
#include<iostream>

#include"CopyAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

CopyAction::CopyAction(ApplicationManager * pApp) :Action(pApp)
{
}
void CopyAction::ReadActionParameters() {
	
}
void CopyAction::Execute() {
	Output* pOut = pManager->GetOutput();
	CFigure* selected = pManager->GetSelected();
	if(selected==NULL){
		pOut->PrintMessage("No selected figure");
		return;
	}
	pManager->setiscut(false);
	selected->SetSelected(false);
    pManager->setClipBoard(selected);
    pOut->PrintMessage("The selected figure is copied to the clipboard");
	
}