#pragma once
#include <wx/wx.h>
#include <wx/sizer.h>

class Block 
{
	int id;
	int x_pos, y_pos;
	wxBitmap bmp;
	int x_offset, y_offset;
	int x_border, y_border;
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