#ifndef CRHOM_H
#define CRHOM_H

#include "CFigure.h"

class CRhombus : public CFigure
{
private:
	Point Corner1;
public:
	CRhombus(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	double area1(int x1, int y1, int x2, int y2, int x3, int y3);
	bool check(int X, int Y);
	virtual bool citefigure(int x, int y);
	virtual CFigure* drawtransition(Point, Output*);
	virtual void printinfo(Output* pOut);
	virtual CFigure* create();
	virtual void setpointsresized(Output* pOut);
	void Save(ofstream &OutFile);
	void Load(ifstream &InFile);
	color StringToColor(string s);
	string name() const;
};

#endif