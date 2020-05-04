#pragma once
#include "LoadAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI/Input.h"
#include "..\GUI/output.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CRhombus.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CTriangle.h"

LoadAction::LoadAction(ApplicationManager *pApp) :Action(pApp)
{
}
//Read parameters for the STB action
void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter the name of the savefile to load: ");
	fileName = pIn->GetSrting(pOut);
	fileName += ".txt";
	ifstream filecheck(fileName);
}
//excute the STB action
void LoadAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	ifstream InLoadShapes(fileName);

	if (InLoadShapes.is_open())
	{
		pManager->DeleteAll();
		pOut->PrintMessage("Valid");
		InLoadShapes >> DrawColor >> FillColor >> FigCount;
		while (InLoadShapes >>name)
		{
			CFigure *Fig;
			if (name == "RECTANGLE")
			{
				Point p1 = { 0 }, p2 = { 0 };
				GfxInfo color;
				Fig = new CRectangle(p1, p2, color);
				Fig->Load(InLoadShapes);
				pManager->AddFigure(Fig);
			}
			else if (name == "ELLIPSE")
			{
				Point p = { 0 };
				GfxInfo color;
				Fig = new CEllipse(p, color);
				Fig->Load(InLoadShapes);
				pManager->AddFigure(Fig);
			}
			else if (name == "TRIANGLE")
			{
				Point p1 = { 0 }, p2 = { 0 }, p3 = { 0 };
				GfxInfo color;
				Fig = new CTriangle(p1, p2, p3, color);
				Fig->Load(InLoadShapes);
				pManager->AddFigure(Fig);
			}
			else if (name == "RHOMBUS")
			{
				Point p = { 0 };
				GfxInfo color;
				Fig = new CRhombus(p, color);
				Fig->Load(InLoadShapes);
				pManager->AddFigure(Fig);
			}
			else if (name == "LINE")
			{
				Point p1 = { 0 }, p2 = { 0 };
				GfxInfo color;
				Fig = new CLine(p1, p2,color);
				Fig->Load(InLoadShapes);
				pManager->AddFigure(Fig);
			}
		}

		InLoadShapes.close();
	}



}
