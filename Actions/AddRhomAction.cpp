#include "AddRhomAction.h"
#include "..\Figures\CRhombus.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRhomAction::AddRhomAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddRhomAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rhombus: Click at center of rhombus.");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	while (P1.y < UI.StatusBarHeight+50 || P1.y > UI.height - UI.StatusBarHeight - 50)
	{
		pOut->PrintMessage("Error! Draw inside the drawing area.");
		pIn->GetPointClicked(P1.x, P1.y);
	}

	RhomGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RhomGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RhomGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRhomAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rhombus with the parameters read from the user
	CRhombus *Rh = new CRhombus(P1, RhomGfxInfo);

	//Add the rhombus to the list of figures
	pManager->AddFigure(Rh);
	Rh->setID(pManager->GetFigureCount());
}
