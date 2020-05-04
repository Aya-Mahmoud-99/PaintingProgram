#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)		
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	resizingfactor=1;
	ID = 0;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::changecolorsubsequentdrawings(color c)
{
	UI.DrawColor = c;
}
void CFigure::fillcolorsubsequentdrawings(color c)
{
	UI.FillColor = c;
}
color CFigure::getdrcolormymade() const
{
	return FigGfxInfo.DrawClr;
}
void CFigure::setID(int id)
{
	ID = id; 
}
int CFigure::GetID() const
{
	return ID;
}
void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
bool CFigure::citefigure(int x, int y)
{
	return false;
}
GfxInfo CFigure::getdrcolor()const{
	return FigGfxInfo;
}
void CFigure::setdrcolor(GfxInfo figfxinfo){
FigGfxInfo=figfxinfo;
};	
 void CFigure::setresizingfactor(double resize)
 {
	 resizingfactor=resize;
 }
 void CFigure::setpointsresized(Output* pOut)
 {

 }



 string CFigure::DrawClrToString()
 {
	 string DrawClr;
	 if ((int)FigGfxInfo.DrawClr.ucRed == 255 && (int)FigGfxInfo.DrawClr.ucGreen == 0 && (int)FigGfxInfo.DrawClr.ucBlue == 0)
		 DrawClr = "RED";
	 else if ((int)FigGfxInfo.DrawClr.ucRed == 0 && (int)FigGfxInfo.DrawClr.ucGreen == 255 && (int)FigGfxInfo.DrawClr.ucBlue == 0)
		 DrawClr = "GREEN";
	 else if ((int)FigGfxInfo.DrawClr.ucRed == 0 && (int)FigGfxInfo.DrawClr.ucGreen == 0 && (int)FigGfxInfo.DrawClr.ucBlue == 255)
		 DrawClr = "BLUE";
	 else if ((int)FigGfxInfo.DrawClr.ucRed == 0 && (int)FigGfxInfo.DrawClr.ucGreen == 0 && (int)FigGfxInfo.DrawClr.ucBlue == 0)
		 DrawClr = "BLACK";
	 else if ((int)FigGfxInfo.DrawClr.ucRed == 255 && (int)FigGfxInfo.DrawClr.ucGreen == 255 && (int)FigGfxInfo.DrawClr.ucBlue == 255)
		 DrawClr = "WHITE";
	 return DrawClr;
 }

 string CFigure::FillClrToString()
 {
	 string FillClr;


	 if ((int)FigGfxInfo.FillClr.ucRed == 255 && (int)FigGfxInfo.FillClr.ucGreen == 0 && (int)FigGfxInfo.FillClr.ucBlue == 0)
		 FillClr = "RED";
	 else if ((int)FigGfxInfo.FillClr.ucRed == 0 && (int)FigGfxInfo.FillClr.ucGreen == 255 && (int)FigGfxInfo.FillClr.ucBlue == 0)
		 FillClr = "GREEN";
	 else if ((int)FigGfxInfo.FillClr.ucRed == 0 && (int)FigGfxInfo.FillClr.ucGreen == 0 && (int)FigGfxInfo.FillClr.ucBlue == 255)
		 FillClr = "BLUE";
	 else if ((int)FigGfxInfo.FillClr.ucRed == 0 && (int)FigGfxInfo.FillClr.ucGreen == 0 && (int)FigGfxInfo.FillClr.ucBlue == 0)
		 FillClr = "BLACK";
	 else if ((int)FigGfxInfo.FillClr.ucRed == 255 && (int)FigGfxInfo.FillClr.ucGreen == 255 && (int)FigGfxInfo.FillClr.ucBlue == 255)
		 FillClr = "WHITE";
	 else
		 FillClr = "NO_FILL";

	 return FillClr;
 }
