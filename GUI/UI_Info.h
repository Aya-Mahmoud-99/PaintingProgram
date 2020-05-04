#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
	MODE_COLOR_SELECT,
	MODE_FIGURE_SELECT,
	MODE_SAVE_BY_TYPE,
	MODE_RESIZE
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_FIGURES,
	ITM_CHNG_DRAW_CLR,
	ITM_CHNG_FILL_CLR,

	ITM_COPY_FIGURE,
	ITM_CUT_FIGURE,
	ITM_PASTE_FIGURE,
	ITM_DEL,
	ITM_SAVE_BY_GRAPH,
	ITM_SAVE_BY_TYPE,
	ITM_LOAD,
	ITM_SELECT,
	ITM_RESIZE,
	ITM_BRING_TO_FRONT,
	ITM_SEND_TO_BACK,
	ITM_PLAYMODE,
	ITM_SOUND,

	ITM_EXIT1,		//Exit item

	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum FigureMenuItem
{
	ITM_RECT,		//Recangle item in menu
	//TODO: Add more items names here
	ITM_TRI,
	ITM_LINE,
	ITM_RHOMBUS,
	ITM_ELLIPSE,
	ITM_RETURN2,
	FIGURE_ITM_COUNT
};

enum SaveMenuItem
{
	ITM_SAVE_RECTANGLE,		//Recangle item in menu
	//TODO: Add more items names here
	ITM_SAVE_TRIANGLE,
	ITM_SAVE_LINE,
	ITM_SAVE_RHOMBUS,
	ITM_SAVE_ELLIPSE,
	ITM_RETURN4,
	SAVE_ITM_COUNT
};

enum ColorMenuItem
{
	ITM_COLOR_RED,
	ITM_COLOR_BLUE,
	ITM_COLOR_GREEN,
	ITM_COLOR_BLACK,
	ITM_COLOR_WHITE,
	ITM_RETURN1,
	COLOR_ITM_COUNT
};


enum ResizeMenuItem
{
	ITM_QUARTERSIZE,
	ITM_HALFSIZE,
	ITM_DOUBLESIZE,
	ITM_QUADSIZE,
	ITM_RETURN3,
	RESIZE_ITM_COUNT
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_PICKBYTYPE,
	ITM_PICKBYCOLOR,
	ITM_DRAWMODE,
	ITM_EXIT2,
	//TODO: Add more items names here
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};






__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	    //Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed

}UI;	//create a global object UI

#endif