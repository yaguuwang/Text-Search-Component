//////////////////////////////////////////////////////////////
// TextSearch.cpp - TextSearch class implementation         //
// ver 1.0                                                  //
// Haoyu Wang, CSE775 - Distributed Object, Spring 2018     //
//////////////////////////////////////////////////////////////
#include "TextSearch.h"
#include <algorithm>
#include <locale>

TextSearch::TextSearch()
{
}
std::vector<int> TextSearch::search(const std::string & file, const std::string & pattern)
{
	std::vector<int> result;
	std::string line;
	int lineNum = 1;
	std::regex reg(pattern);
	std::ifstream inFile(file);
	if (!inFile.good()) {
		std::cout << "\nSomething wrong when reading file: " << file << "\n";
		return result;
	}
	std::string content((std::istreambuf_iterator<char>(inFile)), (std::istreambuf_iterator<char>()));
	content.erase(std::remove(content.begin(), content.end(), '\0'), content.end());
	std::istringstream file_(content);
	while (std::getline(file_, line)) {
		if (std::regex_search(line, reg)) {
			result.push_back(lineNum);
		}
		lineNum++;
	}
	std::cout << "\n";
	return result;
}
// TEST STUB -----------------------------------------------------
//#define TEXTSEARCH_TEST
#ifdef TEXTSEARCH_TEST
int main() {
	TextSearch ts;
	//auto result = ts.search("TextSearch.h", "\\b(include)\\b");
	auto result = ts.search("TextSearch.cpp", "\\b(include)\\b");
	for (auto line : result) {
		std::cout << "line: " << line << "\n";
	}
}
#endif TEXTSEARCH_TEST
