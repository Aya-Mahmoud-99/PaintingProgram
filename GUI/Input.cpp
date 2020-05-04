#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_FIGURES: return TO_FIGURES;
			case ITM_CHNG_FILL_CLR: return TO_COLOR_SELECT_FILL;
			case ITM_CHNG_DRAW_CLR: return TO_COLOR_SELECT_DRAW;

			case ITM_COPY_FIGURE: return COPY_FIGURE;
			case ITM_CUT_FIGURE: return CUT_FIGURE;
			case ITM_PASTE_FIGURE: return PASTE_FIGURE;

			case ITM_SAVE_BY_GRAPH: return SAVE_BY_GRAPH;
			case ITM_SAVE_BY_TYPE: return SAVE_BY_TYPE;
			case ITM_LOAD: return LOAD;
			case ITM_DEL: return DEL;

			case ITM_SELECT: return SELECT;
			case ITM_RESIZE: return RESIZE;
			case ITM_BRING_TO_FRONT: return BRING_TO_FRONT;
			case ITM_SEND_TO_BACK: return SEND_TO_BACK;
			case ITM_PLAYMODE: return TO_PLAY;
			case ITM_SOUND: return TO_SOUND;

			case ITM_EXIT1: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_COLOR_SELECT) //GUI is in color select mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);

			switch (ClickedItemOrder)
			{
			case ITM_COLOR_RED: return COLOR_RED;
			case ITM_COLOR_BLUE: return COLOR_BLUE;
			case ITM_COLOR_GREEN: return COLOR_GREEN;
			case ITM_COLOR_BLACK: return COLOR_BLACK;
			case ITM_COLOR_WHITE: return COLOR_WHITE;
			case ITM_RETURN1: return Return;

			default: return EMPTY;	//A click on empty place in design toolbar
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_FIGURE_SELECT) //GUI is in color select mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_TRI: return DRAW_TRI;
			case ITM_LINE: return DRAW_LINE;
			case ITM_RHOMBUS: return DRAW_RHOMBUS;
			case ITM_ELLIPSE: return DRAW_ELLIPSE;
			case ITM_RETURN2: return Return;

			default: return EMPTY;	//A click on empty place in design toolbar
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_SAVE_BY_TYPE) //GUI is in color select mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return SAVE_RECTANGLE;
			case ITM_TRI: return SAVE_TRIANGLE;
			case ITM_LINE: return SAVE_LINE;
			case ITM_RHOMBUS: return SAVE_RHOMBUS;
			case ITM_ELLIPSE: return SAVE_ELLIPSE;
			case ITM_RETURN4: return Return;

			default: return EMPTY;	//A click on empty place in design toolbar
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_RESIZE) //GUI is in color select mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);

			switch (ClickedItemOrder)
			{
			case ITM_QUARTERSIZE: return QUARTERSIZE;
			case ITM_HALFSIZE: return HALFSIZE;
			case ITM_DOUBLESIZE: return DOUBLESIZE;
			case ITM_QUADSIZE: return QUADSIZE;
			case ITM_RETURN3: return Return;

			default: return EMPTY;	//A click on empty place in design toolbar
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		//return TO_PLAY;	//just for now. This should be updated
				//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_DRAWMODE: return TO_DRAW;
			case ITM_PICKBYTYPE: return PICKBYTYPE;
			case ITM_PICKBYCOLOR: return PICKBYCOLOR;
			case ITM_EXIT2: return EXIT;

			default: return EMPTY;	//A click on empty place in design toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}

}
/////////////////////////////////

Input::~Input()
{
}
