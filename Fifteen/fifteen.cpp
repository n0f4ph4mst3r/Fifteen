#include "Puzzle.h"

Fifteen::Fifteen(wxString file, wxBitmapType format, const int sz) : sourcePath(file), sourceFormat(format), size(sz) {
	Refresh();
}

void Fifteen::Refresh() {
	wxBitmap source;
	source.LoadFile(sourcePath, sourceFormat);
	blockSize = source.GetWidth() / size;

	bool gen_done = false;
	std::vector<int> row;

	//generate a combination and check for parity
	//if the combination is odd -> repeat cycle
	//else create grid from a combination
	while (!gen_done) {
		for (int i = 0; i < size * size; i++) row.push_back(i);
		auto rng = std::default_random_engine{};
		rng.seed(std::chrono::system_clock::now().time_since_epoch().count());
		std::shuffle(std::begin(row), std::end(row), rng);

		int zr = row[0];
		int zero_row = (int)ceil((double)zr / (double)size);

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

	grid.resize(size);
	for (int i = 0; i < size; i++) grid[i].resize(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {

			x = (row[step] % size) * blockSize;
			y = (row[step] / size) * blockSize;

			grid[i][j] = new Block(source.GetSubBitmap(wxRect(x, y, blockSize, blockSize)), row[step] + 1, i * blockSize, j * blockSize);
			step++;
		}
}

//dont forget swap element in the grid, before block movement
void Fifteen::Swap(Block* block1, Block* block2) {
	Block tmp = *block1;
	*block1 = *block2;
	*block2 = tmp;
}

int Fifteen::BlockSize() {
	return blockSize;
}

std::vector<std::vector <Block*>> Fifteen::Grid() {
	return grid;
}

int Fifteen::Size() {
	return size;
}


