#include "gmock/gmock.h"
#include "similaritychecker.cpp"
using std::string;

class SimilarityFixture : public testing::Test {
private:
	similarityChecker sc;
	std::string str1;
	std::string str2;
public:
	void updateScore(const std::string& str1, const std::string & str2) {
		sc.updateLengthScore(str1, str2);
	}

	void checkScore(int expected) {
		EXPECT_EQ(expected, sc.getScore());
	}
};

TEST_F(SimilarityFixture, SameLength) {
	updateScore("ASD", "DSA");
	checkScore(60);
}

TEST_F(SimilarityFixture, LengthDifferenceOver2Times) {
	updateScore("A", "BB");
	checkScore(0);
}

TEST_F(SimilarityFixture, LengthPartialPoint1) {
	updateScore("AAABB", "BAA");
	checkScore(20);
}

TEST_F(SimilarityFixture, LengthPartialPoint2) {
	updateScore("AA", "AAE");
	checkScore(30);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}