#include "gmock/gmock.h"
#include "similaritychecker.cpp"

TEST(CharacterSimilarity, SameLength) {
	string str1 = "ASD";
	string str2 = "DSA";
	similarityChecker sc;
	sc.updateLengthScore(str1, str2);
	EXPECT_EQ(60, sc.getScore());
}

TEST(CharacterSimilarity, LengthDifferenceOver2Times) {
	string str1 = "A";
	string str2 = "BB";
	similarityChecker sc;
	sc.updateLengthScore(str1, str2);
	EXPECT_EQ(0, sc.getScore());
}

TEST(CharacterSimilarity, LengthPartialPoint) {
	string str1 = "AAABB";
	string str2 = "BAA";
	similarityChecker sc;
	sc.updateLengthScore(str1, str2);
	EXPECT_EQ(20, sc.getScore());
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}