#include "addellipseaction.h"
#include "..\Figures\CEllipse.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

//#include <Windows.h>
//#include <Mmsystem.h>

AddEllipseAction::AddEllipseAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddEllipseAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Ellipse: Click at the center");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	while (P1.y < UI.StatusBarHeight + 50 || P1.y > UI.height - UI.StatusBarHeight - 50)
	{
		pOut->PrintMessage("Error! Draw inside the drawing area.");
		pIn->GetPointClicked(P1.x, P1.y);
	}

	EllipseGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	EllipseGfxInfo.DrawClr = pOut->getCrntDrawColor();
	EllipseGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
	//PlaySound(TEXT("circle.wav"), NULL, SND_ASYNC);
}

//Execute the action
void AddEllipseAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CEllipse *R = new CEllipse(P1, EllipseGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
	R->setID(pManager->GetFigureCount());
}