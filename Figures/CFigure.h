#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <iostream>
#include <fstream>
//Base class for all figures
class CFigure
{
protected:
	int ID ;	//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	Output *pOut;
	double resizingfactor;
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	color CFigure::getdrcolormymade() const;

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	virtual bool citefigure(int x , int y ); // ana ely 3amelha 3shan a3rf el point deh gowa el figure wla l2 
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual void changecolorsubsequentdrawings(color c); // ana ely 3amlha
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	void CFigure::fillcolorsubsequentdrawings(color c); // ana ely 3amelha 
	virtual void printinfo(Output* pOut) = 0;	// ana ely 3amelha it should be pure virtual btw 
	virtual CFigure* drawtransition(Point, Output*) = 0;
	virtual void setID(int id);
	virtual int GetID() const;
	GfxInfo getdrcolor() const;
	void setdrcolor(GfxInfo);	
	void setresizingfactor(double);
	virtual CFigure* create()=0;
	virtual void setpointsresized(Output* pOut);
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file


	virtual string DrawClrToString();
	virtual string FillClrToString();

	virtual string name() const = 0;
};
#endif