#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	int ID;
	
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	//void Save(ofstream &OutFile);
	virtual bool citefigure(int x, int y);
	float area(int x1, int y1, int x2, int y2, int x3, int y3);
	bool CRectangle::check(int x1, int y1, int x2, int y2, int x3,int y3, int x4, int y4, int x, int y);
	virtual void printinfo(Output* pOut) ;
	virtual CFigure* drawtransition(Point, Output*);
	virtual CFigure* create();
	virtual void setpointsresized(Output* pOut);
	void Save(ofstream &OutFile);
	void Load(ifstream &InFile);
	color StringToColor(string s);
	string name() const;
};

#endif