#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include <Windows.h> //added for sound
#include <Mmsystem.h> //added for sound
#include <fstream> // added for save

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	int clipboardCount;
	CFigure* SelectedFig; //Pointer to the selected figure 
	CFigure* Clipboard;   //Pointer to the copied/cut figure
	color c;
	GfxInfo colorb4;
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	bool iscut;
	
	bool ToggleSound;

public:	

	ApplicationManager(); 
	~ApplicationManager();
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	color Getcolordirectly(); // ana ely 3mloh
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);
	void ApplicationManager::GetColor(color &inputColor); // ana ely 3amelha
	void Delete(CFigure * x);
	//Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	void SendToForword(CFigure * mymade);
	void SendtoBack(CFigure * mymade);
	void SetSelectedApp(CFigure *selectedFig);
	CFigure *GetSelected();
	void SetunSelectedApp(CFigure *selectedFigT);

	void setClipBoard(CFigure* clipboard);
	void clearClipboard();
	CFigure *GetClipBoard();
	void setiscut(bool);
	bool getiscut();

	void FlipToggleSound();
	bool GetToggleSound();

	void GetResize(double &inputNum);
	void setcolorb4(GfxInfo);
	GfxInfo getcolorb4();

	void SaveAll(ofstream &OutFile);
	void SaveType(ofstream &OutFile);
	int GetType();

	int GetFigureCount();
	void DeleteAll();

	bool TypeExist(string type);
	int GetTypeFigureCount(string type);
	bool ColorExist(string colorname, int &colorcount);
	bool ColorlessCheck();
};

#endif