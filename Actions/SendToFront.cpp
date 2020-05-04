#include "SendToFront.h"
#include "..\ApplicationManager.h"

#include "..\GUI/Input.h"
#include "..\GUI/output.h"


SendToFront::SendToFront(ApplicationManager *pApp) :Action(pApp)
{
}
//Read parameters for the STB action
void SendToFront::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

}
//excute the STB action
void SendToFront::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	CFigure * mymade = pManager->GetSelected();
	if (mymade != NULL)
	{
		pManager->SendToForword(mymade);
		pOut->PrintMessage("Figure sent to forword");
		pManager->SetunSelectedApp(mymade);
	}
	//else print one figure needs to be selected
	else
		pOut->PrintMessage("U have to select a figure first");

}
