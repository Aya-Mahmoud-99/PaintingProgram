#ifndef CTri_H
#define CTri_h

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle (Point, Point, Point,GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	float area(int x1, int y1, int x2, int y2, int x3, int y3);
	bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y);
	virtual bool citefigure(int x, int y);
	virtual void printinfo(Output* pOut);
	virtual CFigure* CTriangle::drawtransition(Point pt, Output* pOut);
	virtual CFigure* create();
	virtual void setpointsresized(Output* pOut);
	void Save(ofstream &OutFile);
	void Load(ifstream &InFile);
	color StringToColor(string s);
	string name() const;
};

#endif