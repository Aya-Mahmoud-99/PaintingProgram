#include "SendToBack.h"
#include "..\ApplicationManager.h"

#include "..\GUI/Input.h"
#include "..\GUI/output.h"


SendToBack::SendToBack(ApplicationManager *pApp) :Action(pApp)
{
}
//Read parameters for the STB action
void SendToBack::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
}
void SendToBack::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	CFigure * mymade = pManager->GetSelected();
	if (mymade!=NULL)
	{
		pManager->SendtoBack(mymade);
		pOut->PrintMessage("Figure sent to back");
		pManager->SetunSelectedApp(mymade);
	}
	//else print one figure needs to be selected
	else
		pOut->PrintMessage("U have to select a figure first");

}
