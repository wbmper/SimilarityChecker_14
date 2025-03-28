#include <string>
#include <iostream>
using std::string;

class similarityChecker {
private:
	int score = 0;
public:
	void updateLengthScore(const string& str1, const string& str2) {
		if (str1.size() == str2.size()) {
			score = 60;
		}
		else if (str1.size() >= 2 * str2.size() || str1.size() * 2 <= str2.size()) {
			score = 0;
		}
		else
		{
			size_t gap = str1.size() - str2.size();
			if (str1.size() > str2.size()) {
				double ratio = 1.0 - static_cast<double>(gap) / str2.size();
				score = static_cast<int>(ratio * 60);
			}
			else
			{
				gap *= (-1);
				double ratio = 1.0 - static_cast<double>(gap) / str1.size();
				score = static_cast<int>(ratio * 60);
			}
		}
	}

	int getScore() const {
		return score;
	}
};
