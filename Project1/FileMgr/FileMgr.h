//////////////////////////////////////////////////////////////
// FileMgr.h - FileMgr class interface                      //
// ver 1.0                                                  //
// Haoyu Wang, CSE775 - Distributed Object, Spring 2018     //
//////////////////////////////////////////////////////////////
/*
* Package Operations:
* -------------------
* The class defination of FileMgr.
*
* Public Interface:
* -----------------
* FileMgr()
* - Constructor for the class
* void setPath(const std::string & path)
* - set path for created obj
* void setPatterns(std::vector<std::string> patterns)
* - set searching pattern with given vector
* void scan()
* - perform scan process after setting path and patterns
* std::pair<std::string, bool> get()
* - get result back which contains a success code and filename.
* - when file exist then success code is true, otherwise success code is false
*
* Required Files:
* ---------------
* Cpp11-BlockingQueue.h
* FileSystem.h"
*
* Maintenance History:
* --------------------
* ver 1.0 : 03 Apr 2017
* - first release
*
*/
#ifndef FILEMGR_H
#define FILEMGR_H

#include "../FileSystem/FileSystem.h"
#include "../CPPBlockingQueue/BlockingQueue.h"
#include <iostream>

class FileMgr {
public:
	FileMgr() {};
	void setPath(const std::string & path) { path_ = path; };
	void setPatterns(std::vector<std::string> patterns) { patterns_ = patterns; };
	void scan() { 
		bq_.clear();
		traverse(path_); 
	};
	std::pair<std::string, bool> get();
private:
	std::string path_;
	std::vector<std::string> patterns_;
	Async::BlockingQueue<std::string> bq_;
	void traverse(std::string path);
};

#endif // !FILEMGR_H
