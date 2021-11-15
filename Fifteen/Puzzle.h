#pragma once
#include <wx/wx.h>
#include <wx/sizer.h>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
static unsigned int g_blockCounter = 0;

//interface for block of puzzle
struct Block
{
	int id; //block number
	int positionX, positionY; //actual block position
	wxBitmap bmp; //block picture, using to draw on panel
	wxPoint offset;
	Block(wxBitmap bmp, int id = g_blockCounter, int x = 0, int y = 0) : bmp(bmp), id(id), positionX(x), positionY(y), offset(wxPoint()) {
		g_blockCounter++;
	}
	~Block() {
		g_blockCounter--;
	}
};

//interface for puzzle
//instance of class is a logical representation of the puzzle
class Fifteen
{
	wxString sourcePath;
	wxBitmapType sourceFormat;

	int size, blockSize;
	std::vector<std::vector <Block*>> grid;

public:
	Fifteen(wxString file, wxBitmapType format = wxBITMAP_TYPE_PNG, const int size = 4);

	void Refresh();
	void Swap(Block* block1, Block* block2); 

	int BlockSize();
	std::vector<std::vector <Block*>> Grid();
	int Size();
};

