#pragma once
#include "Block.h"
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

class Fifteen
{
	const int *size, *w;
	std::vector<std::vector <Block*>> grid;

public:
	Fifteen(wxString file, wxBitmapType format, const int size);

	int BlockSize();
	std::vector<std::vector <Block*>> Grid();
	int Size();

	void Swap(Block* replaceable, Block* substitute);
};