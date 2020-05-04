#include "Exit.h"
#include "..\ApplicationManager.h"

#include "..\GUI/Input.h"
#include "..\GUI/output.h"


Exit::Exit(ApplicationManager *pApp) : Action(pApp)
{}


void Exit::ReadActionParameters()
{}

//Execute action (Exit action)
void Exit::Execute()
{
	pManager->clearClipboard();
}
