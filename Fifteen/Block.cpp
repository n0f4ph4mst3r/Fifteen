#include "Block.h"

Block::Block(wxBitmap bmp, int id, int x, int y) 
	: bmp(bmp), id(id), x_pos(x), y_pos(y), x_border(x_pos), y_border(y_pos)
{
	x_offset = 0;
	y_offset = 0;
	IsMoving = false;
}

int Block::GetX()
{
	return x_pos;
}

int Block::GetY()
{
	return y_pos;
}

int Block::ID()
{
	return id;
}

wxBitmap Block::Bitmap()
{
	return bmp;
}

void Block::Move()
{
	if (x_offset == 0 && y_offset == 0)
	{
		IsMoving = false;
		x_border = x_pos;
		y_border = y_pos;
		return;
	}

	x_pos += x_offset;
	y_pos += y_offset;

	if ((x_pos > x_border && x_offset > 0) || (x_pos < x_border && x_offset < 0))
	{
		x_pos = x_border;
		x_offset = 0;
	}

	if ((y_pos > y_border && y_offset > 0) || (y_pos < y_border && y_offset < 0))
	{
		y_pos = y_border;
		y_offset = 0;
	}
}

void Block::SetOffset (int dx, int dy) 
{
	x_offset = dx;
	y_offset = dy;

	if (x_offset > 0) x_border = x_pos + bmp.GetWidth();
	else if (x_offset < 0) x_border = x_pos - bmp.GetWidth();

	if (y_offset > 0) y_border = y_pos + bmp.GetWidth();
	else if (y_offset < 0) y_border = y_pos - bmp.GetWidth();

	IsMoving = true;
}