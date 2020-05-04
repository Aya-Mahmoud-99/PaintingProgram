#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 70;

	UI.DrawColor = BLACK;	//Drawing color
	UI.FillColor = PURPLE;	//Filling color
	UI.MsgColor = BLACK;		//Messages color
	UI.BkGrndColor = MILKYWHITE;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = YOSRYBLUE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, 0, 1250, 50);
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_FIGURES] = "images\\MenuItems\\Menu_Figures.jpg";
	MenuItemImages[ITM_CHNG_DRAW_CLR] = "images\\MenuItems\\Menu_DrawColor.jpg";
	MenuItemImages[ITM_CHNG_FILL_CLR] = "images\\MenuItems\\Menu_FillColor.jpg";
	MenuItemImages[ITM_EXIT1] = "images\\MenuItems\\Menu_Exit.jpg";

	MenuItemImages[ITM_COPY_FIGURE] = "images\\MenuItems\\Menu_CopyFigure.jpg";
	MenuItemImages[ITM_CUT_FIGURE] = "images\\MenuItems\\Menu_CutFigure.jpg";
	MenuItemImages[ITM_PASTE_FIGURE] = "images\\MenuItems\\Menu_PasteFigure.jpg";
	MenuItemImages[ITM_DEL] = "images\\MenuItems\\Menu_DeleteFigure.jpg";

	MenuItemImages[ITM_SAVE_BY_GRAPH] = "images\\MenuItems\\Menu_SaveByGraph.jpg";
	MenuItemImages[ITM_SAVE_BY_TYPE] = "images\\MenuItems\\Menu_SaveByType.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_Load.jpg";

	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\Menu_Resize.jpg";
	MenuItemImages[ITM_BRING_TO_FRONT] = "images\\MenuItems\\Menu_Bring_To_Front.jpg";
	MenuItemImages[ITM_SEND_TO_BACK] = "images\\MenuItems\\Menu_Send_To_Back.jpg";
	MenuItemImages[ITM_PLAYMODE] = "images\\MenuItems\\Menu_Play.jpg";
	MenuItemImages[ITM_SOUND] = "images\\MenuItems\\Menu_Sound.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////


void Output::CreateSaveByTypeToolBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, 0, 1250, 50);

	UI.InterfaceMode = MODE_SAVE_BY_TYPE;
	string MenuItemImages[SAVE_ITM_COUNT];
	MenuItemImages[ITM_SAVE_RECTANGLE] = "images\\MenuItems\\Menu_Rect.JPG";
	MenuItemImages[ITM_SAVE_TRIANGLE] = "images\\MenuItems\\Menu_Tri.jpg";
	MenuItemImages[ITM_SAVE_LINE] = "images\\MenuItems\\Menu_Line.jpg";
	MenuItemImages[ITM_SAVE_RHOMBUS] = "images\\MenuItems\\Menu_Rhom.jpg";
	MenuItemImages[ITM_SAVE_ELLIPSE] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_RETURN4] = "images\\MenuItems\\return.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < SAVE_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}

void Output::CreateColorSelectToolBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, 0, 1250, 50);

	UI.InterfaceMode = MODE_COLOR_SELECT;
	string MenuItemImages[COLOR_ITM_COUNT];
	MenuItemImages[ITM_COLOR_RED] = "images\\MenuItems\\Menu_ColorRed.jpg";
	MenuItemImages[ITM_COLOR_BLUE] = "images\\MenuItems\\Menu_ColorBlue.jpg";
	MenuItemImages[ITM_COLOR_GREEN] = "images\\MenuItems\\Menu_ColorGreen.jpg";
	MenuItemImages[ITM_COLOR_BLACK] = "images\\MenuItems\\Menu_ColorBlack.jpg";
	MenuItemImages[ITM_COLOR_WHITE] = "images\\MenuItems\\Menu_ColorWhite.jpg";
	MenuItemImages[ITM_RETURN1] = "images\\MenuItems\\return.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < COLOR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}

void Output::CreateResizeToolBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, 0, 1250, 50);

	UI.InterfaceMode = MODE_RESIZE;
	string MenuItemImages[RESIZE_ITM_COUNT];
	MenuItemImages[ITM_QUARTERSIZE] = "images\\MenuItems\\Menu_Quarter.jpg";
	MenuItemImages[ITM_HALFSIZE] = "images\\MenuItems\\Menu_Half.jpg";
	MenuItemImages[ITM_DOUBLESIZE] = "images\\MenuItems\\Menu_Double.jpg";
	MenuItemImages[ITM_QUADSIZE] = "images\\MenuItems\\Menu_Quad.jpg";
	MenuItemImages[ITM_RETURN3] = "images\\MenuItems\\return.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < RESIZE_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}

void Output::CreateFigureSelectToolBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, 0, 1250, 50);

	UI.InterfaceMode = MODE_FIGURE_SELECT;
	string MenuItemImages[FIGURE_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.JPG";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Menu_Tri.jpg";
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\Menu_Line.jpg";
	MenuItemImages[ITM_RHOMBUS] = "images\\MenuItems\\Menu_Rhom.jpg";
	MenuItemImages[ITM_ELLIPSE] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_RETURN2] = "images\\MenuItems\\return.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < FIGURE_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}

void Output::CreatePlayToolBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, 0, 1250, 50);

	UI.InterfaceMode = MODE_PLAY;
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_PICKBYTYPE] = "images\\MenuItems\\Menu_PickByType2.jpg";
	MenuItemImages[ITM_PICKBYCOLOR] = "images\\MenuItems\\Menu_PickByColor2.jpg";
	MenuItemImages[ITM_DRAWMODE] = "images\\MenuItems\\Menu_Draw.jpg";
	MenuItemImages[ITM_EXIT2] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo,double resize, bool selected) const
{
     color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo,double x, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}

void Output::DrawLine(Point P1, Point P2, GfxInfo lineGfxInfo,double x, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = lineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (lineGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(lineGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, FRAME); // heya kanet style bs lma aret el draw line tl3 lazem tktb Frame bdl style
}

void Output::DrawRhom(Point P5, GfxInfo RhomGfxInfo,double resize, bool selected) const
{
	if(P5.y < UI.StatusBarHeight+50*resize|| P5.y > UI.height - UI.StatusBarHeight - 50*resize) resize=1;
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RhomGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RhomGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RhomGfxInfo.FillClr);
	}
	else
		style = FRAME;
	Point P1, P2, P3, P4;
	P1.x = P5.x + 100*resize;
	P1.y = P5.y;
	P2.y = P5.y + 50*resize;
	P2.x = P5.x;
	P3.x = P5.x - 100*resize;
	P3.y = P5.y;
	P4.y = P5.y - 50*resize;
	P4.x = P5.x;
	int Px[4];
	int Py[4];
	Px[0] = P5.x + 100*resize;
	Py[0] = P5.y;
	Py[1] = P5.y + 50*resize;
	Px[1] = P5.x;
	Px[2] = P5.x - 100*resize;
	Py[2] = P5.y;
	Py[3] = P5.y - 50*resize;
	Px[3] = P5.x;
	
	pWind->DrawPolygon(Px, Py, 4, style);

}

void Output::Drawellipse(Point P3, GfxInfo ellGfxInfo,double resize, bool selected) const
{
	if((P3.y < UI.StatusBarHeight + 50 *resize|| P3.y > UI.height - UI.StatusBarHeight - 50*resize)) resize=1;
	Point P1, P2;
	P1.x = P3.x + 100*resize;
	P1.y = P3.y + 50*resize;
	P2.x = P3.x - 100*resize;
	P2.y = P3.y - 50*resize;
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = ellGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (ellGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(ellGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawEllipse(P1.x, P1.y, P2.x, P2.y, style);

}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

