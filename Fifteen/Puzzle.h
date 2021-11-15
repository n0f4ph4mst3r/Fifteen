#pragma once
#include <wx/wx.h>
#include <wx/sizer.h>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

//interface for block of puzzle
struct Block
{
	int id; //block number
	int positionX, positionY; //actual block position
	wxBitmap bmp; //block picture, using to draw on panel
	wxPoint offset;
	Block(wxBitmap bmp, int id, int x = 0, int y = 0) : bmp(bmp), id(id), positionX(x), positionY(y), offset(wxPoint()) {}
};

//interface for puzzle
//instance of class is a logical representation of the puzzle
class Fifteen
{
	const int *size, *w;
	std::vector<std::vector <Block*>> grid;

public:
	Fifteen(wxString file, wxBitmapType format, const int size);

	int BlockSize();
	std::vector<std::vector <Block*>> Grid();
	int Size();

	void Swap(Block* block1, Block* block2); 
};

