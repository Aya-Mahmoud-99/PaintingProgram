#include "SaveByGraphAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI/Input.h"
#include "..\GUI/output.h"
#include <iostream>


SaveByGraphAction::SaveByGraphAction(ApplicationManager *pApp) :Action(pApp)
{
}
//Read parameters for the STB action
void SaveByGraphAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter the savefile name: ");
	fileName = pIn->GetSrting(pOut);
	fileName += ".txt";

}
//excute the STB action
void SaveByGraphAction::Execute()
{
	ReadActionParameters();

	ofstream outSaveShapes(fileName);
	DrawColor = DrawColorToString();
	FillColor = FillColorToString();
	outSaveShapes << DrawColor << "\t" << FillColor << endl;

	pManager->SaveAll(outSaveShapes);
	outSaveShapes.close();
}

string SaveByGraphAction::DrawColorToString()
{
	if ((int)UI.DrawColor.ucRed == 255 && (int)UI.DrawColor.ucGreen == 0 && (int)UI.DrawColor.ucBlue == 0)
		DrawColor = "RED";
	else if ((int)UI.DrawColor.ucRed == 0 && (int)UI.DrawColor.ucGreen == 255 && (int)UI.DrawColor.ucBlue == 0)
		DrawColor = "GREEN";
	else if ((int)UI.DrawColor.ucRed == 0 && (int)UI.DrawColor.ucGreen == 0 && (int)UI.DrawColor.ucBlue == 255)
		DrawColor = "BLUE";
	else if ((int)UI.DrawColor.ucRed == 0 && (int)UI.DrawColor.ucGreen == 0 && (int)UI.DrawColor.ucBlue == 0)
		DrawColor = "BLACK";
	else if ((int)UI.DrawColor.ucRed == 255 && (int)UI.DrawColor.ucGreen == 255 && (int)UI.DrawColor.ucBlue == 255)
		DrawColor = "WHITE";

return DrawColor;
}

string SaveByGraphAction::FillColorToString()
{
	if ((int)UI.FillColor.ucRed == NULL && (int)UI.FillColor.ucGreen == NULL && (int)UI.FillColor.ucBlue == NULL)
		FillColor = "NO_FILL";
	else if ((int)UI.FillColor.ucRed == 255 && (int)UI.FillColor.ucGreen == 0 && (int)UI.FillColor.ucBlue == 0)
		FillColor = "RED";
	else if ((int)UI.FillColor.ucRed == 0 && (int)UI.FillColor.ucGreen == 255 && (int)UI.FillColor.ucBlue == 0)
		FillColor = "GREEN";
	else if ((int)UI.FillColor.ucRed == 0 && (int)UI.FillColor.ucGreen == 0 && (int)UI.FillColor.ucBlue == 255)
		FillColor = "BLUE";
	else if ((int)UI.FillColor.ucRed == 0 && (int)UI.FillColor.ucGreen == 0 && (int)UI.FillColor.ucBlue == 0)
		FillColor = "BLACK";
	else // if ((int)UI.FillColor.ucRed == 255 && (int)UI.FillColor.ucGreen == 255 && (int)UI.FillColor.ucBlue == 255)
		FillColor = "WHITE";

	return FillColor;
}