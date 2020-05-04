#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_RHOMBUS,		//Draw Rhombus
	DRAW_ELLIPSE,		//Draw Ellipse
	//CHNG_DRAW_CLR,	//Change the drawing color
	//CHNG_FILL_CLR,	//Change the filling color

	COLOR_RED,
	COLOR_BLUE,
	COLOR_GREEN,
	COLOR_BLACK,
	COLOR_WHITE,
	Return,


	DEL,			//Delete a figure(s)
	SAVE_BY_GRAPH,			//Save the whole graph to a file, name was previously just "SAVE" edited by nour
	SAVE_BY_TYPE,	//Save the all the figures that have a specific type
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application

	SAVE_RECTANGLE,
	SAVE_ELLIPSE,
	SAVE_LINE,
	SAVE_RHOMBUS,
	SAVE_TRIANGLE,

	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar

	SELECT,
	PICKBYTYPE,
	PICKBYCOLOR,

	COPY_FIGURE,
	CUT_FIGURE,
	PASTE_FIGURE,

	RESIZE,
	QUARTERSIZE,
	HALFSIZE,
	DOUBLESIZE,
	QUADSIZE,

	TO_FIGURES,
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,			//Switch interface to Play mode
	TO_SOUND,
	TO_COLOR_SELECT_DRAW,
	TO_COLOR_SELECT_FILL,

	BRING_TO_FRONT,
	SEND_TO_BACK


	///TODO: Add more action types (if needed)
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif