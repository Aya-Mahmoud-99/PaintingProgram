#pragma once
#include "ToDrawAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI/Input.h"
#include "..\GUI/output.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CRhombus.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CTriangle.h"

ToDrawAction::ToDrawAction(ApplicationManager *pApp) :Action(pApp)
{
	
}

void ToDrawAction::ReadActionParameters()
{

}

void ToDrawAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string name = "saveformodeswitch.txt";
	ifstream LoadFile(name);
	if (LoadFile.is_open())
	{
		pManager->DeleteAll();
		pOut->PrintMessage("Valid");
		LoadFile >> DrawColor >> FillColor >> FigCount;
		while (LoadFile >> name)
		{
			CFigure *Fig;
			if (name == "RECTANGLE")
			{
				Point p1 = { 0 }, p2 = { 0 };
				GfxInfo color;
				Fig = new CRectangle(p1, p2, color);
				Fig->Load(LoadFile);
				pManager->AddFigure(Fig);
			}
			else if (name == "ELLIPSE")
			{
				Point p = { 0 };
				GfxInfo color;
				Fig = new CEllipse(p, color);
				Fig->Load(LoadFile);
				pManager->AddFigure(Fig);
			}
			else if (name == "TRIANGLE")
			{
				Point p1 = { 0 }, p2 = { 0 }, p3 = { 0 };
				GfxInfo color;
				Fig = new CTriangle(p1, p2, p3, color);
				Fig->Load(LoadFile);
				pManager->AddFigure(Fig);
			}
			else if (name == "RHOMBUS")
			{
				Point p = { 0 };
				GfxInfo color;
				Fig = new CRhombus(p, color);
				Fig->Load(LoadFile);
				pManager->AddFigure(Fig);
			}
			else if (name == "LINE")
			{
				Point p1 = { 0 }, p2 = { 0 };
				GfxInfo color;
				Fig = new CLine(p1, p2, color);
				Fig->Load(LoadFile);
				pManager->AddFigure(Fig);
			}
		}

		LoadFile.close();
	}
	pOut->ClearStatusBar();
	pOut->CreateDrawToolBar();
}