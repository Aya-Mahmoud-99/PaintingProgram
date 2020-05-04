#include "PickByColorAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI/Input.h"
#include "..\GUI/output.h"

PickByColorAction::PickByColorAction(ApplicationManager *pApp) :Action(pApp)
{
}

void PickByColorAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	string shapecolor;

	RandomColor(shapecolor);

		while (colorcount != 0)
		{
			CFigure * mymade;
			pIn->GetPointClicked(P1.x, P1.y);
			//if (P1.y > UI.ToolBarHeight || P1.x > (UI.MenuItemWidth * PLAY_ITM_COUNT))
			//{
			//	pOut->PrintMessage("You have quit the game.");
			//	return;
			//}
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
			if (mymade->FillClrToString() == shapecolor)
			{
				pManager->SetSelectedApp(pManager->GetFigure(P1.x, P1.y));
				pManager->Delete(pManager->GetSelected());
				pManager->UpdateInterface();
	
				correct++;
				if (pManager->GetToggleSound())
					PlaySound(TEXT("sounds\\CorrectAnswer.wav"), NULL, SND_ASYNC);
				pOut->PrintMessage("Correct! Click the next " + shapecolor + " shape!");
				colorcount--;
			}
			else
			{
				if (pManager->GetToggleSound())
					PlaySound(TEXT("sounds\\WrongAnswer.wav"), NULL, SND_ASYNC);
				wrong++;
				pOut->PrintMessage("WRONG! Click the next " + shapecolor + " shape!");
			}
		}

		if (pManager->GetToggleSound())
			PlaySound(TEXT("sounds\\FinishPlay.wav"), NULL, SND_ASYNC);

		string correctstring = to_string(correct);
		string wrongstring = to_string(wrong);
		pOut->PrintMessage("Game Over! You had " + correctstring + " right answer/s and " + wrongstring + " wrong answer/s!");
}


void PickByColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetFigureCount() == 0)
	{
		pOut->PrintMessage("You can't play if there are no figures drawn!");
		return;
	}
	if (pManager->ColorlessCheck() == 1)
	{
		pOut->PrintMessage("You can't play if there are colorless figures!");
		return;
	}
	ReadActionParameters();
}
void PickByColorAction::RandomColor(string &shapecolor)
{
	Output* pOut = pManager->GetOutput();
	bool conf = 0;

		while (conf == 0)
	{
		int randomnum = rand() % 5; // results in 0~4 integer
		if (randomnum == 0)
		{
			shapecolor = "RED";
		}
		else if (randomnum == 1)
		{
			shapecolor = "GREEN";
		}
		else if (randomnum == 2)
		{
			shapecolor = "BLUE";
		}
		else if (randomnum == 3)
		{
			shapecolor = "BLACK";
		}
		else if (randomnum == 4)
		{
			shapecolor = "WHITE";
		}
		conf = pManager->ColorExist(shapecolor, colorcount);
		//cout << shapecolor << endl;
		//cout << colorcount;
		//cout << pManager->ColorExist(shapecolor) << endl;
	}
	pOut->PrintMessage("Click on all " + shapecolor + "!");
	//return shapetype;
}
