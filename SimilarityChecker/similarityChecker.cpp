#include <string>
#include <iostream>

class similarityChecker {
private:
	int score = 0;
public:
	void updateLengthScore(const std::string& str1, const std::string& str2) {
		if (isDifference2TimesOver(str1, str2)) {
			return;
		}

		if (isSameSize(str1, str2)) {
			score += 60;
			return;
		}

		score += getPartialPoint(str1, str2);
	}

	int getPartialPoint(const std::string& str1, const std::string& str2)
	{
		int str1Size = static_cast<int>(str1.size());
		int str2Size = static_cast<int>(str2.size());
		int gap = std::abs(str1Size - str2Size);
		int smallSize = std::min(str1Size, str2Size);

		return 60 - gap * 60 / smallSize;
	}

	bool isDifference2TimesOver(const std::string& str1, const std::string& str2) const
	{
		return str1.size() >= 2 * str2.size() || str1.size() * 2 <= str2.size();
	}

	bool isSameSize(const std::string& str1, const std::string& str2) const
	{
		return str1.size() == str2.size();
	}

	int getScore() const {
		return score;
	}
};
