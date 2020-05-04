#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();

	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateColorSelectToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void CreateFigureSelectToolBar() const;
	void CreateSaveByTypeToolBar() const;
	void CreateResizeToolBar() const;

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, double resize ,bool selected = false) const;  //Draw a rectangle

	void DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo,double resize, bool selected) const;

	void DrawLine(Point P1, Point P2, GfxInfo lineGfxInfo,double resize, bool selected) const;

	void DrawRhom(Point P5, GfxInfo RhomGfxInfo,double resize, bool selected) const;

	void Drawellipse(Point P3, GfxInfo ellGfxInfo, double resize,bool selected) const;

	///Make similar functions for drawing all other figure types.

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width


	~Output();
};

#endif