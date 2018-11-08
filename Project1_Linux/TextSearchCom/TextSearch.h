//////////////////////////////////////////////////////////////
// TextSearch.h - TextSearch class interface                //
// ver 1.0                                                  //
// Haoyu Wang, CSE775 - Distributed Object, Spring 2018     //
//////////////////////////////////////////////////////////////
/*
* Package Operations:
* -------------------
* The class defination of TextSearch.
*
* Public Interface:
* -----------------
* TextSearch()
* - Constructor for the class
* std::vector<int> search(std::string file, std::string pattern)
* - search given file with the regular experssion, return vector contains the line where match occurs
* 
* Required Files:
* ---------------
*
* Maintenance History:
* --------------------
* ver 1.0 : 03 Apr 2017
* - first release
*
*/
#ifndef TEXTSEARCH_H
#define TEXTSEATCH_H

#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <regex>
#include <iostream>

class TextSearch {
public:
	TextSearch();
	std::vector<int> search(const std::string & file, const std::string & pattern);
        static TextSearch* getTS() {return new TextSearch();}
private:
};

extern "C" {
    TextSearch* getTS();
}

#endif // !TESTSEARCH_H
