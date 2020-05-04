#include "CRhombus.h"

CRhombus::CRhombus(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
}


void CRhombus::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRhom(Corner1, FigGfxInfo,resizingfactor, Selected);
}
double CRhombus:: area1(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1*(y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}
bool  CRhombus::check(int X, int Y)

{
	if (Y > Corner1.y)
	{
		
		double Area = area1((Corner1.x) + 100, Corner1.y, (Corner1.x) - 100, Corner1.y, Corner1.x, (Corner1.y) + 50);
		double A1 = area1(X, Y, (Corner1.x) - 100, Corner1.y, Corner1.x, (Corner1.y) + 50);
		double A2 = area1((Corner1.x) + 100, Corner1.y, X, Y, Corner1.x, (Corner1.y) + 50);
		double A3 = area1((Corner1.x) + 100, Corner1.y, (Corner1.x) - 100, Corner1.y, X, Y);
		return(Area == A1 + A2 + A3);
	}
	else if (Y < Corner1.y)
	{
		double Area = area1((Corner1.x) + 100, Corner1.y, (Corner1.x) - 100, Corner1.y, Corner1.x, (Corner1.y) - 50);
		double A1 = area1(X, Y, (Corner1.x) - 100, Corner1.y, Corner1.x, (Corner1.y) - 50);
		double A2 = area1((Corner1.x) + 100, Corner1.y, X, Y, Corner1.x, (Corner1.y) - 50);
		double A3 = area1((Corner1.x) + 100, Corner1.y, (Corner1.x) - 100, Corner1.y, X, Y);
		return(Area == A1 + A2 + A3);
	}
	return false;

}

void CRhombus:: printinfo(Output*pOut)
{
	string IDSTR = to_string(GetID());
	string centerx = to_string(Corner1.x);
	string centery = to_string(Corner1.y);
	pOut->PrintMessage("The selected Fig is Rhombus , Its ID = "+IDSTR+" ,its horizontal axis = 100 ,  its vertical axis = 50, and its center is  (" + centerx + "," + centery + ")");
};
		

 bool  CRhombus:: citefigure(int x, int y)
{
	 return check(x,y); 
}

 CFigure* CRhombus::drawtransition(Point pt,Output* pOut){
	 CRhombus* p= new CRhombus(pt,FigGfxInfo);
	 p->setresizingfactor(resizingfactor);
	 if  (pt.y < UI.StatusBarHeight+50*resizingfactor || pt.y > UI.height - UI.StatusBarHeight - 50*resizingfactor){ 
		 p=NULL;
		 delete p;
	 }
	 return p;
  };
 CFigure* CRhombus::create(){
 CFigure* p=new CRhombus(Corner1,FigGfxInfo);
 return p;
 }
 void CRhombus::setpointsresized(Output* pOut)
 {
	
	 return;
 }


 void CRhombus::Save(ofstream & OutFile)
 {
	 OutFile << "RHOMBUS" << "\t" << ID << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << DrawClrToString() << "\t" << FillClrToString() << endl;
 }

 void CRhombus::Load(ifstream &InFile)
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
 color CRhombus::StringToColor(string s)
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

 string CRhombus::name() const
 {
	 return "Rhombus";
 }