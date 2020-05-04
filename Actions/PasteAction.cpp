#pragma once
#include "..\Figures\CEllipse.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CRhombus.h"
#include "..\Figures\CTriangle.h"
#include"PasteAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<iostream>
using namespace std;
PasteAction::PasteAction(ApplicationManager * pApp) :Action(pApp)	
{}
void PasteAction::ReadActionParameters(){
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	// point P1
	pIn->GetPointClicked(P.x, P.y);
};
void PasteAction::Execute() {
		Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure* inclipboard=pManager->GetClipBoard();
	if (inclipboard==NULL){
   pOut->PrintMessage("There is no figure in clipboard");
   return;
	}
	pOut->PrintMessage("select new center");
	ReadActionParameters();
	CFigure* p=inclipboard->drawtransition(P,pOut);
	while(p==NULL){
pOut->PrintMessage("The pasted figure would be outside the drawing area!! please select new center");
ReadActionParameters();
	p=inclipboard->drawtransition(P,pOut);
	}
	if(pManager->getiscut()){
		pManager->Delete(pManager->GetClipBoard());
		delete pManager->GetClipBoard();
		p->setdrcolor(pManager->getcolorb4());
		pManager->setiscut(false);
	}
	pManager->AddFigure(p);
	p->setID(pManager->GetFigureCount());
	pOut->ClearStatusBar();

}