#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}


void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawLine(Corner1, Corner2, FigGfxInfo,resizingfactor, Selected); //function of phase 1
}
/*bool CLine::collinear(int x1, int y1, int x2,
	int y2, int x3, int y3)
{
	// Calculation the area of  
	// triangle. We have skipped  
	// multiplication with 0.5  
	// to avoid floating point  
	// computations  
	int a = x1 * (y2 - y3) +
		x2 * (y3 - y1) +
		x3 * (y1 - y2);

	if (a == 0)
		return true;
	else
		return false;
}
*/
double CLine::CalcDistance(Point A, Point B) const 
{
	return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}

bool CLine::citefigure(int x, int y)
{
	
		//Creates a point P(x,y) to use in CalcDistance
		Point P;
		P.x = x;
		P.y = y;
		//Calculate distances AB, AP, and PB, where A and B are the start and the end respectively
		double AB = CalcDistance(Corner1, Corner2);
		double AP = CalcDistance(Corner1, P);
		double PB = CalcDistance(Corner2, P);
		//P is on the line if AB = (AP+PB) , 0.25 is an error margin
		return (abs(AB - (AP + PB)) <= 0.2);
	
}
void CLine::printinfo(Output* pOut)
{
	string IDSTR = to_string(GetID());
	string center1x = to_string(Corner1.x);
	string center1y = to_string(Corner1.y);
	string center2x = to_string(Corner2.x);
	string center2y = to_string(Corner2.y);
	float len = sqrt(pow((Corner1.x - Corner2.x), 2) + pow((Corner1.y - Corner2.y), 2));
	string length = to_string(len);
	pOut->PrintMessage("The selected Fig is Line , its ID = " +IDSTR+" its length = " +length+ " , and its its start point is  (" + center1x + " " + center1y + ") and its end point is (" + center2x + " " + center2y + ")" );

}
CFigure* CLine::drawtransition(Point pt,Output* pOut){
	Point center;
	center.x=(Corner1.x+Corner2.x)/2;
	center.y=(Corner1.y+Corner2.y)/2;
	  int dx=pt.x-center.x;
	  int dy=pt.y-center.y;
	  Point Corner22,Corner11;
	  Corner11.x=Corner1.x+dx;
	  Corner11.y=Corner1.y+dy;
	  Corner22.x=Corner2.x+dx;
	  Corner22.y=Corner2.y+dy;
	CFigure* p=new CLine(Corner11,Corner22,FigGfxInfo);
	if (Corner11.y < UI.StatusBarHeight || Corner11.y > UI.height - UI.StatusBarHeight||Corner22.y < UI.StatusBarHeight || Corner22.y > UI.height - UI.StatusBarHeight)
	return p;
  };
CFigure* CLine::create(){
 CFigure* p=new CLine(Corner1,Corner2,FigGfxInfo);
 return p;
 }
void CLine::setpointsresized(Output* pOut){
		 Point center;
	center.x=(Corner1.x+Corner2.x)/2;
	center.y=(Corner1.y+Corner2.y)/2;
	double dxp1=Corner1.x-center.x;
	double dyp1=Corner1.y-center.y;
	double dxp2=Corner2.x-center.x;
	double dyp2=Corner2.y-center.y;
	if((center.y+dyp1*resizingfactor)< UI.StatusBarHeight || (center.y+dyp1*resizingfactor)> (UI.height - UI.StatusBarHeight)||(center.y+dyp1*resizingfactor)< UI.StatusBarHeight || (center.y+dyp1*resizingfactor)>( UI.height - UI.StatusBarHeight))
	{
		
		return;
	}
	Corner1.x=center.x+dxp1*resizingfactor;
	Corner1.y=center.y+dyp1*resizingfactor;
	Corner2.x=center.x+dxp2*resizingfactor;
	Corner2.y=center.y+dyp2*resizingfactor;
}

void CLine::Save(ofstream &OutFile)
{
	OutFile << "LINE" << "\t" << ID << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t" << Corner2.y
		<< "\t" << DrawClrToString() << endl; //no fill color for line
}

void CLine::Load(ifstream &InFile)
{
	string DrawColor;
	InFile >> ID;
	InFile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
	InFile >> DrawColor;
	FigGfxInfo.DrawClr = StringToColor(DrawColor);

}
color CLine::StringToColor(string s)
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

string CLine::name() const
{
	return "Line";
}