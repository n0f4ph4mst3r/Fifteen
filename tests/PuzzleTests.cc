#include <gtest/gtest.h>
#include <Puzzle.h>

class RefreshTests : public ::testing::Test
{
protected:
	void SetUp()
	{
		testingPuzzle = new Puzzle();
		testingPuzzle->Refresh();
	}
	void TearDown()
	{
		delete testingPuzzle;
	}
	Puzzle* testingPuzzle;
};
TEST_F(RefreshTests, Refresh_ByDefault_Size)
{
	const int sizeExpected = 4;

	ASSERT_EQ(sizeExpected, testingPuzzle->Size(), L"Invlaid size");
}
TEST_F(RefreshTests, Refresh_ByDefault_GridSize)
{
	const int sizeExpected = 4;
	bool widthIsCorrect = true;
	bool heightIsCorrect = true;

	if (sizeExpected != testingPuzzle->Grid().size()) heightIsCorrect = false;
	for (int i = 0; i < 4; i++)
		if (sizeExpected != testingPuzzle->Grid()[i].size()) widthIsCorrect = false;

	ASSERT_TRUE(heightIsCorrect, L"Expected result does not match height of grid");
	ASSERT_TRUE(widthIsCorrect, L"Expected result does not match width of grid");
}

TEST_F(RefreshTests, Refresh_ByDefault_NumbersInSequence)
{
	int sum = 0;
	std::vector<int> row;

	for (int i = 0; i < testingPuzzle->Size(); i++) {
		for (int j = 0; j < testingPuzzle->Size(); j++) {
			row.push_back(testingPuzzle->Grid()[i][j]->id);
			sum += row[row.size() - 1];
		}
	}

	ASSERT_EQ((int)row.size(), 16, L"Invalid quantity of blocks");
	ASSERT_EQ(sum, 136, L"Incorrect sequence");
}

TEST_F(RefreshTests, Refresh_ByDefault_EvenCombination)
{
	int sum = 0;
	std::vector<int> row;
	bool IsEven = true;

	for (int i = 0; i < testingPuzzle->Size(); i++)
		for (int j = 0; j < testingPuzzle->Size(); j++) {
			row.push_back(testingPuzzle->Grid()[i][j]->id);
			sum += testingPuzzle->Grid()[i][j]->id;
		}
	if (sum % 2 != 0) IsEven = false;

	ASSERT_TRUE(IsEven, L"Odd sequence");
}