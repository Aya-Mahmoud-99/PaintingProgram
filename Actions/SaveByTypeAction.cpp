#include "SaveByTypeAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI/Input.h"
#include "..\GUI/output.h"
#include <iostream>


SaveByTypeAction::SaveByTypeAction(ApplicationManager *pApp) :Action(pApp)
{
}

void SaveByTypeAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Saving by type! Select a figure type:");
	pOut->CreateSaveByTypeToolBar();

	//fileName = "fileName.txt";

	if (pManager->GetFigureCount() == 0)
	{
		pOut->PrintMessage("There are no figures to save.");
		return;
	}

}

void SaveByTypeAction::Execute()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();

	//fileName = "blank.txt";
	pOut->PrintMessage("Enter the savefile name: ");
	fileName = pIn->GetSrting(pOut);
	fileName += ".txt";

	ofstream outSaveShapes(fileName);
	DrawColor = DrawColorToString();
	FillColor = FillColorToString();
	outSaveShapes << DrawColor << "\t" << FillColor << endl;

	pManager->SaveType(outSaveShapes);


	outSaveShapes.close();

	pOut->CreateDrawToolBar();
	pOut->PrintMessage("Successfully saved!");
}

string SaveByTypeAction::DrawColorToString()
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

string SaveByTypeAction::FillColorToString()
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