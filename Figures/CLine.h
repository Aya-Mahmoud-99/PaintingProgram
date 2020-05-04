#ifndef CLine_H
#define CLine_H

#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	double CalcDistance(Point A, Point B) const;
	virtual bool citefigure(int x, int y);
	//bool collinear(int x1, int y1, int x2, int y2, int x3, int y3);
	virtual void printinfo(Output* pOut);
	CFigure* drawtransition(Point, Output*);
	virtual CFigure* create();
	virtual void setpointsresized(Output* pOut);
	void Save(ofstream &OutFile);
	void Load(ifstream &InFile);
	color StringToColor(string s);
	string name() const;
};

#endif
