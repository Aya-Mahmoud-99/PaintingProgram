#include "CELLipse.h"
#include <string>
CEllipse::CEllipse(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
}


void CEllipse::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->Drawellipse(Corner1, FigGfxInfo,resizingfactor,Selected);
}
bool CEllipse::citefigure(int xx, int yy)
{
	return (((pow((xx - Corner1.x), 2) / pow(100, 2)) + (pow((yy - Corner1.y), 2) / pow(50, 2))) <= 1.0); 
}

void CEllipse::printinfo(Output* pOut)
{
	string IDSTR = to_string(GetID());
	string centerx = to_string(Corner1.x);
	string centery = to_string(Corner1.y);
	pOut->PrintMessage("The selected Fig is Ellipse , its ID = " + IDSTR + " ,its horizontal axis = 100 ,  its vertical axis = 50, and its center is  (" +centerx+ "," +centery + ")" );
}
CFigure* CEllipse::drawtransition(Point pt,Output* pOut){
	CFigure* p=new CEllipse(pt,FigGfxInfo);
	 p->setresizingfactor(resizingfactor);
	if(pt.y < UI.StatusBarHeight + 50*resizingfactor || pt.y > UI.height - UI.StatusBarHeight - 50*resizingfactor){
		p=NULL;
		delete p;
	}
	 return p;
  };
CFigure* CEllipse::create()
{
 CFigure* p=new CEllipse(Corner1,FigGfxInfo);
 return p;
 }
void CEllipse::setpointsresized(Output* pOut)
{
	return;
}


void CEllipse::Save(ofstream & OutFile)
{
	OutFile << "ELLIPSE" << "\t" << ID << "\t" << Corner1.x << "\t" << Corner1.y <<
		"\t" << DrawClrToString() << "\t" << FillClrToString() << endl;
}

void CEllipse::Load(ifstream &InFile)
{
	string DrawColor, FillColor;
	InFile >> ID;
	InFile >> Corner1.x >> Corner1.y;
	InFile >> DrawColor >> FillColor;
	FigGfxInfo.DrawClr = StringToColor(DrawColor);
	FigGfxInfo.FillClr = StringToColor(FillColor);
	if (FigGfxInfo.FillClr == TURQUOISE)
	{
		FigGfxInfo.isFilled = false;
	}
	else
	{
		FigGfxInfo.isFilled = true;
	}
}

color CEllipse::StringToColor(string s)
{
	if (s == "BLACK")
	{
		return BLACK;
	}
	else if (s == "BLUE")
	{
		return BLUE;
	}
	else if (s == "RED")
	{
		return RED;
	}
	else if (s == "GREEN")
	{
		return GREEN;
	}
	else if (s == "WHITE")
	{
		return WHITE;
	}
	else if (s == "NO_FILL")
	{
		return TURQUOISE;
	}
}

string CEllipse::name() const
{
	return "Ellipse";
}