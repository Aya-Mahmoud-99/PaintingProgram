#ifndef CELLIPSE_H
#define CELLIPSE_H

#include "CFigure.h"

class CEllipse : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
public:
	CEllipse(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool citefigure(int x, int y);
	virtual void printinfo(Output* pOut);
	virtual CFigure* CEllipse::drawtransition(Point pt, Output* pOut);
	virtual CFigure* create();
	virtual void setpointsresized(Output* pOut);
	void Save(ofstream &OutFile);
	void Load(ifstream &InFile);
	color StringToColor(string s);
	string name() const;
};

#endif