#pragma once
#include <wx/wx.h>
#include <wx/sizer.h>
//interface for block of puzzle
//instance of class keep block and his number
//in addition, all operations related to movement are called from this class
class Block 
{
	int id; //block number
	int x_pos, y_pos; //actual block position
	wxBitmap bmp; //block picture, using to draw on panel
	int x_offset, y_offset;
	int x_border, y_border; //used to restrict movement
public :
	Block(wxBitmap bmp, int id, int x, int y);

	int GetX();
	int GetY();
	int ID();
	wxBitmap Bitmap();
	bool IsMoving;

	void Move();
	void SetOffset(int dx, int dy);
};