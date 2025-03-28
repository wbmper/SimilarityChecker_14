#include "gmock/gmock.h"
#include "similaritychecker.cpp"
using std::string;

class SimilarityFixture : public testing::Test {
private:
	similarityChecker sc;
public:
	void updateScore(const std::string& str1, const std::string & str2) {
		sc.updateLengthScore(str1, str2);
		sc.updateAlphaScore(str1, str2);
	}

	void checkScore(int expected) {
		EXPECT_EQ(expected, sc.getScore());
	}
};

TEST_F(SimilarityFixture, LengthSameAlphaSame) {
	updateScore("ASD", "DSA");
	checkScore(100);
}

TEST_F(SimilarityFixture, LengthDifferenceOver2TimesAlphaTotallyDifferent) {
	updateScore("A", "BB");
	checkScore(0);
}

TEST_F(SimilarityFixture, LengthPartialPoint1Alpha3Same) {
	updateScore("AAABB", "BAA");
	checkScore(60); // 20 + 40
}

TEST_F(SimilarityFixture, LengthPartialPoint2Alpha1Same) {
	updateScore("AA", "AAE");
	checkScore(50); // 30 + 20
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}