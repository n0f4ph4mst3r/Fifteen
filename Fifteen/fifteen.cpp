#include "Fifteen.h"

Fifteen::Fifteen(wxString file, wxBitmapType format, const int sz) {
	const static int size = sz;
	this->size = &size;
	wxBitmap source;
	source.LoadFile(file, format);
	const static int w = source.GetWidth() / size;
	this->w = &w;

	bool gen_done = false;
	std::vector<int> row;

	//generate a combination and check for parity
	//if the combination is odd -> repeat cycle
	//else create grid from a combination
	while (!gen_done) {
		for (int i = 0; i < sz*sz; i++) row.push_back(i);
		auto rng = std::default_random_engine{};
		rng.seed(std::chrono::system_clock::now().time_since_epoch().count());
		std::shuffle(std::begin(row), std::end(row), rng);

		int zr = row[0];
		int zero_row = (int)ceil((double)zr / (double)sz);

		int sum = 0;

		for (int i = 0; i < row.size() - 1; i++) {
			int var1 = row[i];
			if (var1 == 0) continue;

			for (int j = i + 1; j <= row.size() - 1; j++) {
				int var2 = row[j];
				if (var2 == 0) continue;
				if (var1 > var2) sum++;
			}
		}

		sum += zero_row;

		if (sum % 2 == 0) gen_done = true;
		else row.resize(0);
	}

	int step = 0;
	int x, y;

	grid.resize(sz);
	for (int i = 0; i < sz; i++) grid[i].resize(sz);

	for (int i = 0; i < sz; i++)
		for (int j = 0; j < sz; j++) {

			x = (row[step] % sz)*w;
			y = (row[step] / sz)*w;

			grid[i][j] = new Block(source.GetSubBitmap(wxRect(x, y, w, w)), row[step]+1, i*w, j*w);
			step++;
		}
}

int Fifteen::BlockSize() {
	return *w;
}

std::vector<std::vector <Block*>> Fifteen::Grid() {
	return grid;
}

int Fifteen::Size() {
	return *size;
}

//dont forget swap element in the grid, before block movement
void Fifteen::Swap(Block* block1, Block* block2) {
	Block tmp = *block1;
	*block1 = *block2;
	*block2 = tmp;
}
