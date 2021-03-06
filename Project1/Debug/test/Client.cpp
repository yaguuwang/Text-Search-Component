///////////////////////////////////////////////////////////////
// Client.cpp - The Client of the TextSearchTool             //
// ver 1.0                                                   //
// Haoyu Wang, CSE775 - Distributed Object, Spring 2018      //
///////////////////////////////////////////////////////////////
/*
* Package Operations:
* -------------------
* - This package contains the TextSearchEngine class that talks
* the FileMgr component and the TextSearch component
* - This package contains the main entry of this project
*
* Required Files:
* ---------------
* ../FileMgrCom/FileMgrCom_i.h
* ../TextSearchComp/TextSearchCom_i.h
*
* Maintenance History:
* --------------------
* ver 1.0 : 03 Apr 2018
* - first release
*
*/

#include "stdafx.h"
#include "../FileMgrCom/FileMgrCom_i.h"
#include "../TextSearchCom/TextSearchCom_i.h"
#include <atlbase.h>
#include <iostream>
#include <string>
#include <vector>

// helper function
// - convert ATL::BSTR to std::string
inline std::string BSTR2STDSTR(const BSTR bstr, int cp = CP_UTF8) {
	std::wstring ws(bstr);
	std::string stdstr(ws.begin(), ws.end());
	return stdstr;
}

// helper function
// - get boundary of safearray within given variant
std::pair<long, long> getBound(VARIANT * v) {
	std::pair<long, long> bound;
	long lbound, ubound;
	::SafeArrayGetUBound(v->parray, 1, &ubound);
	::SafeArrayGetLBound(v->parray, 1, &lbound);
	bound.first = lbound;
	bound.second = ubound;
	return bound;
}

// helper function
// - set up FileMgrComObj
void usingFileMgrCom(CComQIPtr<IFileMgrComObj>& obj, std::string path, std::vector<std::string>& pattern) {
	if (obj) {
		CComBSTR path_(path.c_str());
		obj->setFM();
		obj->setPath(path_);
		std::vector<CComBSTR> patterns;
		for (auto p : pattern) patterns.push_back(p.c_str());
		SAFEARRAYBOUND bound[1];
		bound->lLbound = 0;
		bound->cElements = patterns.size();
		SAFEARRAY * sa = SafeArrayCreate(VT_BSTR, 1, bound);
		VARIANT temp;
		for (long i = 0; i < long(patterns.size()); i++) {
			SafeArrayPutElement(sa, &i, patterns[i]);
		}
		CComVariant patterns_(sa);
		temp.vt = VT_EMPTY;
		patterns_.Detach(&temp);
		obj->setPatterns(&temp);
		obj->scan();
	}
}

// helper function
// - set up TextSearchComObj and do the search
void usingTextSearchCom(CComQIPtr<ITextSearchComObj>& tsObj, CComQIPtr<IFileMgrComObj>& fmObj, std::string reg) {
	if (tsObj && fmObj) {
		tsObj->setTS();
		CComBSTR reg(reg.c_str());
		VARIANT file;
		while (true) {
			fmObj->get(&file);
			auto bound = getBound(&file);
			if (bound.second - bound.first == 0) break;
			BSTR filePath;
			long i = 1;
			SafeArrayGetElement(file.parray, &i, &filePath);
			VARIANT lineNum;

			std::cout << "Found " << BSTR2STDSTR(reg) << " in file: " << BSTR2STDSTR(filePath) << "\n";
			tsObj->search(filePath, reg, &lineNum);
			bound = getBound(&lineNum);
			for (long i = bound.first; i <= bound.second; i++) {
				int num;
				::SafeArrayGetElement(lineNum.parray, &i, &num);
				if (num == -1) continue;
				std::cout << "\tAt line " << num << "\n";
			}
			std::cout << "\n";
		}
	}
}

int main(int argc, char** argv)
{
	std::cout << "\n775 - DO Project 1 Demo\n";
	std::cout << "=======================\n\n";
	std::string path, reg;
	std::vector<std::string> patterns;
	if (argc < 3) {
		std::cout << "Invalid arguments! Usage: client [path] [reg] [patterns] ...\n";
		return 0;
	}
	else
	{
		path = argv[1];
		reg = argv[2];
		for (int i = 3; i<argc; i++)
			patterns.push_back(argv[i]);
	}
	CoInitialize(NULL);
	CComQIPtr<IFileMgrComObj> pFileMgrComObj;
	pFileMgrComObj.CoCreateInstance(CLSID_FileMgrComObj);
	usingFileMgrCom(pFileMgrComObj, path, patterns);
	CComQIPtr<ITextSearchComObj> pTextSearchComObj;
	pTextSearchComObj.CoCreateInstance(CLSID_TextSearchComObj);
	usingTextSearchCom(pTextSearchComObj, pFileMgrComObj, reg);
	system("PAUSE");
	return 0;
}

