#include "PickByTypeAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI/Input.h"
#include "..\GUI/output.h"

PickByTypeAction::PickByTypeAction(ApplicationManager *pApp) :Action(pApp)
{
}

void PickByTypeAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	RandomShape(shapetype);
	int repeat = pManager->GetTypeFigureCount(shapetype);
	while (repeat != 0)
	{
		pIn->GetPointClicked(P1.x, P1.y);
		//if (!(P1.y < UI.ToolBarHeight && P1.x < (UI.MenuItemWidth * PLAY_ITM_COUNT)))
		//{
		//	pOut->PrintMessage("You have quit the game.");
		//	return;
		//}
		CFigure * mymade;
		mymade = pManager->GetFigure(P1.x, P1.y);
		while (mymade == NULL)
		{
			pOut->PrintMessage("Click a shape please.");
			pIn->GetPointClicked(P1.x, P1.y);
			//if (P1.y > UI.ToolBarHeight || P1.x > (UI.MenuItemWidth * PLAY_ITM_COUNT))
			//{
			//	pOut->PrintMessage("You have quit the game.");
			//	return;
			//}
			mymade = pManager->GetFigure(P1.x, P1.y);
		}
		if (mymade->name() == shapetype)
		{
			pManager->SetSelectedApp(pManager->GetFigure(P1.x, P1.y));
			pManager->Delete(pManager->GetSelected());
			pManager->UpdateInterface();

			correct++;
			if (pManager->GetToggleSound())
				PlaySound(TEXT("sounds\\CorrectAnswer.wav"), NULL, SND_ASYNC);
			pOut->PrintMessage("Correct! Click the next " + shapetype + "!");
			repeat--;
		}
		else
		{
			if (pManager->GetToggleSound())
				PlaySound(TEXT("sounds\\WrongAnswer.wav"), NULL, SND_ASYNC);
			wrong++;
			pOut->PrintMessage("WRONG! Click the next " + shapetype + "!");
		}

		//cout << mymade->name();
		//cout << shapetype;
		//pIn->GetPointClicked(P1.x, P1.y);
	}

	if (pManager->GetToggleSound())
		PlaySound(TEXT("sounds\\FinishPlay.wav"), NULL, SND_ASYNC);

	string correctstring = to_string(correct);
	string wrongstring = to_string(wrong);
	pOut->PrintMessage("Game Over! You had " + correctstring + " right answer/s and " + wrongstring + " wrong answer/s!");

}

void PickByTypeAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetFigureCount() == 0)
	{
		pOut->PrintMessage("You can't play if there are no figures drawn!");
		return;
	}
	ReadActionParameters();
}

void PickByTypeAction::RandomShape(string &shapetype)
{
	Output* pOut = pManager->GetOutput();

	bool conf = 0;

	//string shapetype;
	while (conf == 0)
	{
		int randomnum = rand() % 5; // results in 0~4 integer
		if (randomnum == 0)
		{
			shapetype = "Rectangle";
		}
		else if (randomnum == 1)
		{
			shapetype = "Triangle";
		}
		else if (randomnum == 2)
		{
			shapetype = "Ellipse";
		}
		else if (randomnum == 3)
		{
			shapetype = "Rhombus";
		}
		else if (randomnum == 4)
		{
			shapetype = "Line";
		}
		conf = pManager->TypeExist(shapetype);
		cout << shapetype << endl;
		cout << pManager->TypeExist(shapetype) << endl;
	}
	pOut->PrintMessage("Click on all " + shapetype + "!");
	//return shapetype;
}