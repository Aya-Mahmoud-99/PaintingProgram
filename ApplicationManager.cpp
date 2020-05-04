#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"Actions\AddTriAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddRhomAction.h"
#include "Actions\AddEllipseAction.h"
#include "Actions\SelectAction.h"
#include"Actions/AddDeleteAction.h"
#include"Actions/Changecolor.h"
#include "Actions/Fillcolor.h"
#include "Actions\ResizeAction.h"
#include "Actions\CopyAction.h"
#include "Actions\PasteAction.h"
#include "Actions\CutAction.h"
#include "Actions/Exit.h"
#include "Actions/SendToBack.h"
#include "Actions/SendToFront.h"
#include "Actions\SaveByGraphAction.h"
#include "Actions\SaveByTypeAction.h"
#include "Actions\PickByTypeAction.h"
#include "Actions\PickByColorAction.h"
#include "Actions\LoadAction.h"
#include "Actions\ToPlayAction.h"
#include "Actions\ToDrawAction.h"
#include "Figures\CRectangle.h"
#include "Figures\CEllipse.h"
#include "Figures\CRhombus.h"
#include "Figures\CLine.h"
#include "Figures\CTriangle.h"
#include <iostream>
#include <windows.h>
#include <MMsystem.h>
#include <stdio.h>
#include "Actions\ResizeAction.h"




//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;
	setiscut(false);
	setClipBoard(NULL);
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	color c;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{

		case DRAW_RECT:
			if (GetToggleSound())
				PlaySound(TEXT("sounds\\rectangle.wav"), NULL, SND_ASYNC);
			pAct = new AddRectAction(this);
			pOut->CreateDrawToolBar();
			break;

		case DRAW_LINE:
			if (GetToggleSound())
			PlaySound(TEXT("sounds\\line.wav"), NULL, SND_ASYNC);
			///create AddLineAction here
			pAct = new AddLineAction(this);
			pOut->CreateDrawToolBar();
			break;

		case DRAW_TRI:
			if (GetToggleSound())
			PlaySound(TEXT("sounds\\Triangle.wav"), NULL, SND_ASYNC);
			pAct = new AddTriAction(this);
			pOut->CreateDrawToolBar();
			break;

		case DRAW_RHOMBUS:
			if (GetToggleSound())
			PlaySound(TEXT("sounds\\Rhombus.wav"), NULL, SND_ASYNC);
			pAct = new AddRhomAction(this);
			pOut->CreateDrawToolBar();
			break;

		case DRAW_ELLIPSE:
			if (GetToggleSound())
			PlaySound(TEXT("sounds\\ellipse.wav"), NULL, SND_ASYNC);
			pAct = new AddEllipseAction(this); 
			pOut->CreateDrawToolBar();
			break;

		case TO_FIGURES:
			pOut->CreateFigureSelectToolBar();
			break;

		case TO_COLOR_SELECT_DRAW:
			pAct = new Changecolor(this);
			pOut->CreateColorSelectToolBar();
			pOut->PrintMessage("Selecting draw color");
			break;

		case TO_COLOR_SELECT_FILL:
			pAct = new Fillcolor(this);
			pOut->CreateColorSelectToolBar();//
			//pOut->PrintMessage("Selecting fill color");
			break;

		case COLOR_RED:
			pOut->CreateDrawToolBar();
			//pOut->PrintMessage("U have selected the Red color");

			break;

		case COLOR_BLUE:
			//if (GetToggleSound())
			//PlaySound(TEXT("sounds\\Blue.wav"), NULL, SND_ASYNC);
			pOut->CreateDrawToolBar();
			break;

		case COLOR_GREEN:
			pOut->CreateDrawToolBar();
			break;

		case COLOR_BLACK:
			pOut->CreateDrawToolBar();
			break;

		case COLOR_WHITE:
			pOut->CreateDrawToolBar();
			break;

		case Return:
			pOut->CreateDrawToolBar();
			break;

		case SELECT:
			if (GetToggleSound())
			PlaySound(TEXT("sounds\\Select.wav"), NULL, SND_ASYNC);
			pAct = new SelectAction(this);
			pOut->CreateDrawToolBar();
			break;

		case COPY_FIGURE:
			if (GetToggleSound())
			PlaySound(TEXT("sounds\\Copy.wav"), NULL, SND_ASYNC);
			pAct = new CopyAction(this);
			pOut->CreateDrawToolBar();
			break;

		case CUT_FIGURE:
			if (GetToggleSound())
			PlaySound(TEXT("sounds\\cut.wav"), NULL, SND_ASYNC);
			pAct = new CutAction(this);

			pOut->CreateDrawToolBar();
			break;

		case PASTE_FIGURE:
			if (GetToggleSound())
			PlaySound(TEXT("sounds\\paste.wav"), NULL, SND_ASYNC);
			pAct = new PasteAction(this);
			pOut->CreateDrawToolBar();	
			break;

		case SAVE_BY_GRAPH:
			if (FigCount == 0)
				pOut->PrintMessage("There are no figures to save.");
			else
				pAct = new SaveByGraphAction(this);
			break;

		case SAVE_BY_TYPE:
			if (FigCount == 0)
				pOut->PrintMessage("There are no figures to save.");
			else
				pAct = new SaveByTypeAction(this);
			break;

		case DEL:
			if (GetToggleSound())
			PlaySound(TEXT("sounds\\Delete.wav"), NULL, SND_ASYNC);
			pAct = new AddDeleteAction(this);
			break;


		case LOAD:
			pAct = new LoadAction(this);
			break;

		case PICKBYTYPE:
			pAct = new PickByTypeAction(this);
			break;

		case PICKBYCOLOR:
			pAct = new PickByColorAction(this);
			break;

		case TO_DRAW:
			pAct = new ToDrawAction(this);
			break;

		case TO_PLAY:
			if (GetToggleSound())
				PlaySound(TEXT("sounds\\playmood.wav"), NULL, SND_ASYNC);
			pAct = new ToPlayAction(this);
			break;


		case SEND_TO_BACK:
			if (GetToggleSound())
			PlaySound(TEXT("sounds\\sendbackward.wav"), NULL, SND_ASYNC);
			pAct = new SendToBack(this);
			pOut->CreateDrawToolBar();
			break;

		case BRING_TO_FRONT:
			if (GetToggleSound())
			PlaySound(TEXT("sounds\\sendforward.wav"), NULL, SND_ASYNC);
			pAct = new SendToFront(this);
			pOut->CreateDrawToolBar();
			break;

		case TO_SOUND:
			FlipToggleSound();
			if (GetToggleSound())
				pOut->PrintMessage("Sound is enabled!");
			else
				pOut->PrintMessage("Sound is disabled!");
			break;

		case RESIZE:
			if (GetToggleSound())
			PlaySound(TEXT("sounds\\resize.wav"), NULL, SND_ASYNC);
			pAct = new ResizeAction(this);
			pOut->CreateResizeToolBar();
			pOut->PrintMessage("Resizing! Choose a size: ");
			break;

		case EXIT:
			if (GetToggleSound())
			PlaySound(TEXT("sounds\\exitloading.wav"), NULL, SND_ASYNC);
			pAct = new Exit(this);
			pOut->CreateDrawToolBar();
			pOut->PrintMessage("EXIT ... LOADING ..... .... ... .. .");
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
color ApplicationManager::Getcolordirectly()
{
		return c;
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//==================================================================================//
//						function Change color							            //
void ApplicationManager::GetColor(color &inputColor)
{


	//Inputting draw color action
	ActionType inputColorAction = pIn->GetUserAction();

	switch (inputColorAction) 
	{
	case COLOR_BLACK:
		inputColor = BLACK;
		break;

	case COLOR_WHITE:
		inputColor = WHITE;
		break;

	case COLOR_RED:
		inputColor = RED;
		break;

	case COLOR_GREEN:
		inputColor = GREEN;
		break;

	case COLOR_BLUE:
		PlaySound(TEXT("sounds\\Blue.wav"), NULL, SND_ASYNC);
		cout << "Blue is called " << endl;

		inputColor = BLUE;
		break;

	default:
		pOut->CreateDrawToolBar();
	
	}

}
	//Restoring the draw toolbar
void ApplicationManager::GetResize(double &inputNum)
{
	ActionType inputNumberAction = pIn->GetUserAction();

	switch (inputNumberAction)
	{
	case QUARTERSIZE:
		inputNum = 0.25;
		break;

	case HALFSIZE:
		inputNum = 0.5;
		break;

	case DOUBLESIZE:
		inputNum = 2.0;
		break;

	case QUADSIZE:
		inputNum = 4.0;
		break;

	default:
		pOut->CreateDrawToolBar();
	}

}






//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
	{

		FigList[FigCount] = pFig;
		FigList[FigCount]->setID(FigCount);
		cout << FigCount << endl;
		cout << FigList[FigCount]->GetID();
		FigCount++;
	}
}
void ApplicationManager::SendtoBack(CFigure * mymade)
{
	/*int i = mymade->GetID();
	CFigure*Temp = mymade;
	mymade = FigList[0];
	FigList[0] = Temp;*/
	//checking if the element sent is not the last shape 
	int index = mymade->GetID();
	
		//putting the shape in temp
		CFigure* temp = FigList[index];
		//Loops on all figures ,starting at the index of the Selected One, shifting them back 1 element and setting their ID
		for (int i = index; i > 0; i--)
		{

			FigList[i] = FigList[i - 1];
			FigList[i]->setID(i);
		}
		FigList[0] = temp;
		FigList[0]->setID(0);
	pOut->ClearDrawArea();
}
void ApplicationManager::SendToForword(CFigure * mymade)
{
	int index = mymade->GetID();
	
		//putting the shape in temp
		CFigure* temp = FigList[index];
		//Loops on all figures ,starting at the index of the Selected One, shifting them forword 1 element and setting their new ID
		for (int i = index; i < FigCount-1; i++)
		{

			FigList[i] = FigList[i + 1];
			FigList[i]->setID(i);
		}
		FigList[FigCount-1] = temp;
		FigList[FigCount-1]->setID(FigCount-1);
	pOut->ClearDrawArea();
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::Delete(CFigure * sentfigure)
{
	if (sentfigure != NULL)
	{
		for (int i = FigCount - 1; i >= 0; i--)
		{
			if (FigList[i]==sentfigure)
			{
				FigList[i] = FigList[FigCount - 1];
				FigList[FigCount - 1] = NULL;
				FigCount--;
			}
		}
	}
	cout << "is called " << endl;
	sentfigure = NULL;
	pOut->ClearDrawArea();
}

CFigure *ApplicationManager::GetFigure(int xx, int yy) const
{

	//If a figure is found return a pointer to it.
	for (int i = FigCount-1; i >= 0; i--)
	{
		if (FigList[i]->citefigure(xx, yy) == true)
		{
			return FigList[i];
		}
	}
	//if this point (x,y) does not belong to any figure return NULL
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//
void ApplicationManager::clearClipboard()
{
	if (Clipboard != NULL)
		{
		Clipboard = NULL;
		delete Clipboard;
		pOut->PrintMessage("DONE CLEARED");
		}
}
//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
	delete FigList[i];
	delete pIn;
	delete pOut;
	
}

void ApplicationManager :: SetSelectedApp(CFigure *selectedFigT)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] == selectedFigT)
			continue;
		FigList[i]->SetSelected(false);
	}
	//selectedFigT->SetSelected(true);
	SelectedFig = selectedFigT;
	SelectedFig->SetSelected(true);
}
void ApplicationManager::SetunSelectedApp(CFigure *selectedFigT)
{
	//selectedFigT->SetSelected(false);
	SelectedFig = selectedFigT;
	SelectedFig->SetSelected(false);
}

CFigure* ApplicationManager :: GetSelected()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected() == true)
		{
			return FigList[i];
		}
	}
	return NULL;
}
void ApplicationManager::setClipBoard(CFigure* clipboard)
{
	Clipboard = clipboard;
}
CFigure* ApplicationManager::GetClipBoard()
{
	return Clipboard;
}
void ApplicationManager::setiscut(bool ISCUT) {
	iscut = ISCUT;
}
bool ApplicationManager::getiscut() {
	return iscut;
}
/*CFigure* ApplicationManager::GetClipBoard()
{

}
*/
/*void ApplicationManager::changeDrawcolor(ActionType ActType)
{
	Action* pActnew = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case:RED

	}

}*/

void ApplicationManager::FlipToggleSound()
{
	ToggleSound = !ToggleSound;
}
bool ApplicationManager::GetToggleSound()
{
	return ToggleSound;
}
void ApplicationManager::setcolorb4(GfxInfo b4){
	colorb4=b4;
};
GfxInfo ApplicationManager::getcolorb4(){
	return colorb4;
};


void ApplicationManager::SaveAll(ofstream &OutFile)
{
	OutFile << FigCount << endl;
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(OutFile);
		//OutFile << SaveByGraph
		//SaveByGraphAction->DrawColorToString();
	}
	pOut->PrintMessage("Successfully saved!");
}

bool ApplicationManager::TypeExist(string type)
{
	bool conf = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->name() == type)
		{
			conf = 1;
			return conf;
		}
	}
	return conf;
}

bool ApplicationManager::ColorExist(string colorname, int &colorcount)
{
	colorcount = 0;
	bool conf = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->FillClrToString() == colorname)
		{
			conf = 1;
			colorcount++;
			cout << FigList[i]->FillClrToString();
			cout << colorname;
		}
	}
	return conf;
}

bool ApplicationManager::ColorlessCheck()
{
	for (int i = 0; i < FigCount; i++)
	{
		string x = FigList[i]->FillClrToString();
		if (!(x == "RED" || x == "GREEN" || x == "BLUE" || x == "BLACK" || x == "WHITE"))
		{
			return 1; //colorless exists
		}
	}
	return 0;
}


int ApplicationManager::GetType()
{
	ActionType inputNumberAction = pIn->GetUserAction();

	int type = -1;

	if (inputNumberAction == SAVE_RECTANGLE)
		type = 0;
	else if (inputNumberAction == SAVE_TRIANGLE)
		type = 1;
	else if (inputNumberAction == SAVE_ELLIPSE)
		type = 2;
	else if (inputNumberAction == SAVE_RHOMBUS)
		type = 3;
	else if (inputNumberAction == SAVE_LINE)
		type = 4;
	else if (inputNumberAction == Return)
		pOut->CreateDrawToolBar();


	return type;
}


void ApplicationManager::SaveType(ofstream &OutFile)
{
	//OutFile << FigCount << endl;
	int newID = 1;
	int typegotten = GetType();
	int index = 0;
	int *arr = new int[FigCount];

	if (typegotten == 0)
		for (int i = 0; i < FigCount; i++)
		{
			CRectangle*ptr = dynamic_cast<CRectangle*>(FigList[i]);
			if (ptr != NULL)
			{
				FigList[i]->setID(newID++);
				arr[index++] = i;
				//FigList[i]->Save(OutFile);
			}
		}

	else if (typegotten == 1)
	{
		for (int i = 0; i < FigCount; i++)
		{
			CTriangle*ptr = dynamic_cast<CTriangle*>(FigList[i]);
			if (ptr != NULL)
			{
				FigList[i]->setID(newID++);
				arr[index++] = i;
				//FigList[i]->Save(OutFile);
			}
		}
	}

	else if (typegotten == 2)
	{
		for (int i = 0; i < FigCount; i++)
		{
			CEllipse*ptr = dynamic_cast<CEllipse*>(FigList[i]);
			if (ptr != NULL)
			{
				FigList[i]->setID(newID++);
				arr[index++] = i;
				//FigList[i]->Save(OutFile);
			}
		}
	}

	else if (typegotten == 3)
	{
		for (int i = 0; i < FigCount; i++)
		{
			CRhombus*ptr = dynamic_cast<CRhombus*>(FigList[i]);
			if (ptr != NULL)
			{
				FigList[i]->setID(newID++);
				arr[index++] = i;
				//FigList[i]->Save(OutFile);
			}
		}
	}

	else if (typegotten == 4)
	{
		for (int i = 0; i < FigCount; i++)
		{
			CLine*ptr = dynamic_cast<CLine*>(FigList[i]);
			if (ptr != NULL)
			{
				FigList[i]->setID(newID++);
				arr[index++] = i;
				//FigList[i]->Save(OutFile);
			}
		}
	}
	OutFile << index << endl;
	for (int i = 0; i < index; i++)
		FigList[arr[i]]->Save(OutFile);
	arr = NULL;
	delete[] arr;
}

int ApplicationManager::GetFigureCount()
{
	return FigCount;
}

int ApplicationManager::GetTypeFigureCount(string type)
{
	int TypeFigCount = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->name() == type)
			TypeFigCount++;
	}
	return TypeFigCount;
}

void ApplicationManager::DeleteAll()
{
	for (int i = 0; i < FigCount; i++)
	{
		Delete(FigList[i]);
	}
}