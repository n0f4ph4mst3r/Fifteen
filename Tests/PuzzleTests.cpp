#include "pch.h"
#include "CppUnitTest.h"
#include "../Fifteen/Puzzle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PuzzleTests
{
	TEST_CLASS(RefreshTests) {
public:
	TEST_METHOD(Refresh_ByDefault_Size) {
		const int sizeExpected = 4;
		Puzzle testingPuzzle = Puzzle();

		testingPuzzle.Refresh();

		Assert::AreEqual(sizeExpected, testingPuzzle.Size(), L"Invlaid size");
	}

	TEST_METHOD(Refresh_ByDefault_GridSize) {
		const int sizeExpected = 4;
		Puzzle testingPuzzle = Puzzle();
		bool widthIsCorrect = true;
		bool heightIsCorrect = true;

		testingPuzzle.Refresh();
		if (sizeExpected != testingPuzzle.Grid().size()) heightIsCorrect = false;
		for (int i = 0; i < 4; i++)
			if (sizeExpected != testingPuzzle.Grid()[i].size()) widthIsCorrect = false;

		Assert::IsTrue(heightIsCorrect, L"Expected result does not match height of grid");
		Assert::IsTrue(widthIsCorrect, L"Expected result does not match width of grid");
	}

	TEST_METHOD(Refresh_ByDefault_NumbersInSequence) {
		int sum = 0;
		std::vector<int> row;
		Puzzle *testingPuzzle = new Puzzle();

		testingPuzzle->Refresh();
			for (int i = 0; i < testingPuzzle->Size(); i++) { 
				for (int j = 0; j < testingPuzzle->Size(); j++) { 
					row.push_back(testingPuzzle->Grid()[i][j]->id);
					sum += row[row.size() - 1];
				}
			}

		Assert::AreEqual((int)row.size(), 16, L"Invalid quantity of blocks");
		Assert::AreEqual(sum, 136, L"Incorrect sequence");
	}

	TEST_METHOD(Refresh_ByDefault_EvenCombination) {
		int sum = 0;
		std::vector<int> row;
		Puzzle testingPuzzle = Puzzle();
		bool IsEven = true;

		testingPuzzle.Refresh();
		for (int i = 0; i < testingPuzzle.Size(); i++)
			for (int j = 0; j < testingPuzzle.Size(); j++) {
				row.push_back(testingPuzzle.Grid()[i][j]->id);
				sum += testingPuzzle.Grid()[i][j]->id;
			}
		if (sum % 2 != 0) IsEven = false;

		Assert::IsTrue(IsEven, L"Odd sequence");
	}
	};
}
