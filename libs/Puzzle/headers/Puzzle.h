//declaration of classes Block and Puzzle
#pragma once
#include <wx/wx.h>
#include <wx/sizer.h>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
static unsigned int g_blockCounter = 0;

//block of puzzle
struct Block {
	int id; //block number
	int positionX, positionY; //actual block position
	wxImage blockImage; //block picture, using to draw on panel
	wxPoint offset; //using for movement

	Block(wxBitmap bmp, int id = g_blockCounter, int x = 0, int y = 0) : id(id), positionX(x), positionY(y), offset(wxPoint()) {
		blockImage = bmp.ConvertToImage();
		g_blockCounter++;
	}

	~Block() {
		g_blockCounter--;
	}
};

//this class is a logical representation of the puzzle
class Puzzle {
	wxImage source;

	int size, blockSize;
	std::vector<std::vector <Block*>> grid;

public:
	Puzzle();
	Puzzle(wxBitmap* source, const int size = 4);

	void Refresh();
	void Swap(Block* block1, Block* block2); 

	int BlockSize();
	std::vector<std::vector <Block*>> Grid();
	int Size();
};

