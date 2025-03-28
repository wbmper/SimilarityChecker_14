#include <string>
#include <iostream>
#include <set>
#include <algorithm>

class similarityChecker {
private:
	int score = 0;
	std::set<char> alphabetSet1;
	std::set<char> alphabetSet2;
public:
	void updateAlphaScore(const std::string& str1, const std::string& str2) {
		setAlphabetSet(str1, str2);
		score += getAlphaPartialPoint();
	}

	int getAlphaPartialPoint()
	{
		std::set<char> alphabetUnionSet;
		std::set_union(
			alphabetSet1.begin(), alphabetSet1.end(),
			alphabetSet2.begin(), alphabetSet2.end(),
			std::inserter(alphabetUnionSet, alphabetUnionSet.begin())
		);

		int sameCount = 0;
		int totalCount = alphabetUnionSet.size();
		for (char alphabet : alphabetUnionSet) {
			if (alphabetSet1.count(alphabet) && alphabetSet2.count(alphabet)) {
				sameCount++;
			}
		}

		return (sameCount * 40 / totalCount);
	}

	void setAlphabetSet(const std::string& str1, const std::string& str2)
	{
		for (char alphabet : str1) {
			alphabetSet1.insert(alphabet);
		}

		for (char alphabet : str2) {
			alphabetSet2.insert(alphabet);
		}
	}

	void updateLengthScore(const std::string& str1, const std::string& str2) {
		if (isDifference2TimesOver(str1, str2)) {
			return;
		}

		if (isSameSize(str1, str2)) {
			score += 60;
			return;
		}

		score += getLengthPartialPoint(str1, str2);
	}

	int getLengthPartialPoint(const std::string& str1, const std::string& str2)
	{
		int str1Size = static_cast<int>(str1.size());
		int str2Size = static_cast<int>(str2.size());
		int gap = (str1Size > str2Size) ? (str1Size - str2Size) : (str2Size - str1Size);
		int smallSize = (str1Size > str2Size) ? str2Size : str1Size;

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
