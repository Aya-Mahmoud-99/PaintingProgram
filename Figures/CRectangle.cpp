#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo,resizingfactor, Selected);
}
//conrner 1.x corner1.y 
//
float CRectangle:: area(int x1, int y1, int x2, int y2,int x3, int y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) +
		x3 * (y1 - y2)) / 2.0);
}
bool CRectangle::check(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x, int y)
{
	/* Calculate area of rectangle ABCD */
	float A = area(x1, y1, x2, y2, x3, y3) +
		area(x1, y1, x4, y4, x3, y3);

	/* Calculate area of triangle PAB */
	float A1 = area(x, y, x1, y1, x2, y2);

	/* Calculate area of triangle PBC */
	float A2 = area(x, y, x2, y2, x3, y3);

	/* Calculate area of triangle PCD */
	float A3 = area(x, y, x3, y3, x4, y4);

	/* Calculate area of triangle PAD */
	float A4 = area(x, y, x1, y1, x4, y4);

	/* Check if sum of A1, A2, A3 and A4
	   is same as A */
	return (A == A1 + A2 + A3 + A4);
}
 bool CRectangle:: citefigure(int x, int y)
 {
	
	return check(Corner1.x, Corner1.y, Corner2.x, Corner1.y, Corner2.x, Corner2.y, Corner1.x, Corner2.y, x, y);
	
 }
 void CRectangle::printinfo(Output* pOut)
 {
	 string IDSTR = to_string (GetID());
	 string center1x = to_string(Corner1.x);
	 string center1y = to_string(Corner1.y);
	 string center2x = to_string(Corner2.x);
	 string center2y = to_string(Corner2.y);
	 int l = abs(Corner1.x - Corner2.x);
	 int w = abs(Corner1.y - Corner2.y);
	 string length = to_string(l);
	 string width = to_string(w);
	 pOut->PrintMessage("The selected Fig is Rectangle , its ID = " +IDSTR+" , and its start point is  (" + center1x + " " + center1y + ") and its end point is (" + center2x + " " + center2y + ") the length and width = " 
		+ length +","+ width );

 }

 CFigure* CRectangle::drawtransition(Point pt,Output* pOut){
	  Point center;
	  center.x=(Corner1.x+Corner2.x)/2;
	  center.y=(Corner1.y+Corner2.y)/2;
	  int dx=pt.x-center.x;
	  int dy=pt.y-center.y;
	  Point Corner11;
	  Corner11.x=Corner1.x+dx;
	  Corner11.y=Corner1.y+dy;
	  Point Corner22;
	  Corner22.x=Corner2.x+dx;
	  Corner22.y=Corner2.y+dy;
	 CRectangle * p = new CRectangle(Corner11,Corner22,FigGfxInfo);
	  if(Corner11.y < UI.StatusBarHeight || Corner11.y > UI.height - UI.StatusBarHeight||Corner22.y < UI.StatusBarHeight || Corner22.y > UI.height - UI.StatusBarHeight){
		  delete p;
		  p=NULL;
	  }
	  return p;
  };
 CFigure* CRectangle::create(){
 CFigure* p=new CRectangle(Corner1,Corner2,FigGfxInfo);
 return p;
 }
 void CRectangle::setpointsresized(Output* pOut){
	 Point center;
	center.x=(Corner1.x+Corner2.x)/2;
	center.y=(Corner1.y+Corner2.y)/2;
	double dxp1=Corner1.x-center.x;
	double dyp1=Corner1.y-center.y;
	double dxp2=Corner2.x-center.x;
	double dyp2=Corner2.y-center.y;
	if((center.y+dyp1*resizingfactor)< UI.StatusBarHeight || (center.y+dyp1*resizingfactor)> (UI.height - UI.StatusBarHeight)||(center.y+dyp1*resizingfactor)< UI.StatusBarHeight || (center.y+dyp1*resizingfactor)>( UI.height - UI.StatusBarHeight))
	{
		
		return ;
	}
	Corner1.x=center.x+dxp1*resizingfactor;
	Corner1.y=center.y+dyp1*resizingfactor;
	Corner2.x=center.x+dxp2*resizingfactor;
	Corner2.y=center.y+dyp2*resizingfactor;

 }

 void CRectangle::Save(ofstream & OutFile)
 {
	 OutFile << "RECTANGLE" << "\t" << ID << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t" << Corner2.y << "\t" << DrawClrToString() << "\t" << FillClrToString() << endl;
 }

 void CRectangle::Load(ifstream &InFile)
 {
	 string DrawColor, FillColor;
	 InFile >> ID;
	 InFile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
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

 color CRectangle::StringToColor(string s)
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
 string CRectangle::name() const
 {
	 return "Rectangle";
 }