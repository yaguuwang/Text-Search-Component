//////////////////////////////////////////////////////////////
// FileMgr.cpp - FileMgr class implementation               //
// ver 1.0                                                  //
// Haoyu Wang, CSE775 - Distributed Object, Spring 2018     //
//////////////////////////////////////////////////////////////
#include "FileMgr.h"

std::pair<std::string, bool> FileMgr::get()
{
	std::pair<std::string, bool> result("", false);
	if (!bq_.size()) return result;
	result.first = bq_.deQ();
	result.second = true;
	return result;
}

void FileMgr::traverse(std::string path)
{
	for (auto pattern : patterns_) {
		auto temp = FileSystem::Directory::getFiles(path, pattern);
		for (auto& t : temp) bq_.enQ(FileSystem::Path::fileSpec(path, t));
	}
	for (auto dir : FileSystem::Directory::getDirectories(path, "*")) {
		if (dir == "." || dir == "..") continue;
		traverse(FileSystem::Path::fileSpec(path, dir));
	}
}


// TEST_STUB ---------------------------------------------------------
//#define FILEMGR_TEST
#ifdef FILEMGR_TEST
int main() {
	std::vector<std::string> patterns = {"*.txt", "*.cpp", "*.h"};
	FileMgr fm();
	fm.setPath(FileSystem::Directory::getCurrentDirectory());
	fm.setPatterns(patterns);
	fm.scan();

	while (true) {
		auto file = fm.get();
		if (!file.second) break;
		std::cout << "File: " << file.first << "\n";
	}
}
#endif // FILEMGR_TEST
