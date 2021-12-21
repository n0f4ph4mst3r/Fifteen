//declaration of classes Block and Puzzle
#pragma once
#include <wx/wx.h>
#include <wx/sizer.h>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <memory> 
static unsigned int g_blockCounter = 0;

//block of puzzle
struct Block {
	int id; //block number
	int positionX, positionY; //actual block position
	wxImage blockImage; //block picture, using to draw on panel
	wxPoint offset; //using for movement

	Block(wxBitmap bmp, const int id = g_blockCounter, const int x = 0, const int y = 0) 
		: id(id), positionX(x), positionY(y), offset(wxPoint(0,0)) {
		blockImage = bmp.ConvertToImage();
		g_blockCounter++;
	}

	~Block() {
		g_blockCounter--;
	}
};

//this class is a logical representation of the puzzle
using BlockPtr = std::shared_ptr<Block>;
using PuzzleGrid = std::vector<std::vector <BlockPtr>>;

class Puzzle {
	wxImage source;

	int size, blockSize;
	PuzzleGrid grid;

public:
	Puzzle();
	Puzzle(wxBitmap& source, const int size = 4);

	void Refresh();

	int BlockSize();
	PuzzleGrid Grid();
	int Size();
};

