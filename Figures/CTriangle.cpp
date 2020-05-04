#include"CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2,Point P3 ,GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a triangle on the screen	
	pOut->DrawTri(Corner1, Corner2, Corner3, FigGfxInfo,resizingfactor, Selected);
}
float CTriangle::area(int x1, int y1, int x2, int y2,
	int x3, int y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) +
		x3 * (y1 - y2)) / 2.0);
}
bool CTriangle::isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{
	
	/* Calculate area of triangle ABC */
	float A = area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);

	/* Calculate area of triangle PBC */
	float A1 = area(x, y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);

	/* Calculate area of triangle PAC */
	float A2 = area(Corner1.x, Corner1.y, x, y, Corner3.x, Corner3.y);

	/* Calculate area of triangle PAB */
	float A3 = area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, x, y);

	/* Check if sum of A1, A2 and A3 is same as A */
	return (A == A1 + A2 + A3);
}
bool CTriangle:: citefigure(int x, int y)
{
	return isInside(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y, x, y);
}
void  CTriangle:: printinfo(Output* pOut)
{
	string IDSTR = to_string(GetID());
	string center1x = to_string(Corner1.x);
	string center1y = to_string(Corner1.y);
	string center2x = to_string(Corner2.x);
	string center2y = to_string(Corner2.y);
	string center3x = to_string(Corner3.x);
	string center3y = to_string(Corner3.y);
	pOut->PrintMessage("The selected Fig is Triangle , its ID = "+IDSTR+ " and its points are  (" + center1x + " " + center1y + ") and its 2nd point is (" + center2x + " " + center2y + ") and its 3rd point is (" + center3x + " " + center3y + ")");

}

CFigure* CTriangle::drawtransition(Point pt,Output* pOut){
	Point center;
	center.x=(Corner1.x+Corner2.x+Corner3.x)/3;
	center.y=(Corner1.y+Corner2.y+Corner3.y)/3;
	  int dx=pt.x-center.x;
	  int dy=pt.y-center.y;
	  Point Corner22,Corner33,Corner11;
	  Corner11.x=Corner1.x+dx;
	  Corner11.y=Corner1.y+dy;
	  Corner22.x=Corner2.x+dx;
	  Corner22.y=Corner2.y+dy;
	  Corner33.x=Corner3.x+dx;
	  Corner33.y=Corner3.y+dy;
	  CFigure* p=new CTriangle(Corner11,Corner22,Corner33,FigGfxInfo);
	  if (Corner11.y < UI.StatusBarHeight || Corner11.y > UI.height - UI.StatusBarHeight||Corner22.y < UI.StatusBarHeight || Corner22.y > UI.height - UI.StatusBarHeight||Corner33.y < UI.StatusBarHeight || Corner33.y > UI.height - UI.StatusBarHeight){
		  p=NULL;
		  delete p;
	  }
	  return p;
  };
CFigure* CTriangle::create(){
 CFigure* p=new CTriangle(Corner1,Corner2,Corner3,FigGfxInfo);
 return p;
 }
void CTriangle::setpointsresized(Output* pOut){
	Point center;
		center.x=(Corner1.x+Corner2.x+Corner3.x)/3;
	center.y=(Corner1.y+Corner2.y+Corner3.y)/3;
	double dxp1=Corner1.x-center.x;
	double dyp1=Corner1.y-center.y;
	double dxp2=Corner2.x-center.x;
	double dyp2=Corner2.y-center.y;
    double dxp3=Corner3.x-center.x;
	double dyp3=Corner3.y-center.y;
	if((center.y+dyp1*resizingfactor)< UI.StatusBarHeight || (center.y+dyp1*resizingfactor)> (UI.height - UI.StatusBarHeight)||(center.y+dyp1*resizingfactor)< UI.StatusBarHeight || (center.y+dyp1*resizingfactor)>( UI.height - UI.StatusBarHeight)||(center.y+dyp3*resizingfactor)< UI.StatusBarHeight || (center.y+dyp3*resizingfactor)> (UI.height - UI.StatusBarHeight))
	{
		
		return;
	}
	Corner1.x=center.x+dxp1*resizingfactor;
	Corner1.y=center.y+dyp1*resizingfactor;
	Corner2.x=center.x+dxp2*resizingfactor;
	Corner2.y=center.y+dyp2*resizingfactor;
	Corner3.x=center.x+dxp3*resizingfactor;
	Corner3.y=center.y+dyp3*resizingfactor;
}


void CTriangle::Save(ofstream & OutFile)
{
	OutFile << "TRIANGLE" << "\t" << ID << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t" << Corner2.y << "\t" << Corner3.x << "\t" << Corner3.y << "\t" << DrawClrToString() << "\t" << FillClrToString() << endl;
}

void CTriangle::Load(ifstream &InFile)
{

	string DrawColor, FillColor;
	InFile >> ID;
	InFile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y;
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
color CTriangle::StringToColor(string s)
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


string CTriangle::name() const
{
	return "Triangle";
}