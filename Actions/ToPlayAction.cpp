#include "ToPlayAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI/Input.h"
#include "..\GUI/output.h"

ToPlayAction::ToPlayAction(ApplicationManager *pApp) :Action(pApp)
{
}

void ToPlayAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	SaveFile.open("saveformodeswitch.txt");

	DrawColor = DrawColorToString();
	FillColor = FillColorToString();
	SaveFile << DrawColor << "\t" << FillColor << endl;

	pManager->SaveAll(SaveFile);
	SaveFile.close();
	pOut->ClearStatusBar();
	pOut->CreatePlayToolBar();
}

void ToPlayAction::Execute()
{
	ReadActionParameters();
}


string ToPlayAction::DrawColorToString()
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

string ToPlayAction::FillColorToString()
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