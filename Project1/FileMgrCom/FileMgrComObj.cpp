// FileMgrComObj.cpp : Implementation of CFileMgrComObj

#include "stdafx.h"
#include "FileMgrComObj.h"
#include <atlsafe.h>

// CFileMgrComObj



STDMETHODIMP CFileMgrComObj::setPath(BSTR path)
{
	// TODO: Add your implementation code here
	if (set) {
		fm->setPath(BSTR2STDSTR(path));
	}
	return S_OK;
}


STDMETHODIMP CFileMgrComObj::scan()
{
	// TODO: Add your implementation code here
	if (set) {
		fm->scan();
	}
	return S_OK;
}


STDMETHODIMP CFileMgrComObj::setPatterns(VARIANT* patterns)
{
	// TODO: Add your implementation code here
	if (set) {
		long lbound, ubound;
		::SafeArrayGetLBound(patterns->parray, 1, &lbound);
		::SafeArrayGetUBound(patterns->parray, 1, &ubound);
		long size = ubound - lbound + 1;
		std::vector<std::string> patterns_;
		BSTR temp;
		for (long i = lbound; i <= ubound; i++) {
			::SafeArrayGetElement(patterns->parray, &i, &temp);
			patterns_.push_back(BSTR2STDSTR(temp));
		}
		fm->setPatterns(patterns_);
	}
	return S_OK;
}


STDMETHODIMP CFileMgrComObj::get(VARIANT* result)
{
	// TODO: Add your implementation code here
	if (set) {
		auto temp = fm->get();
		CComSafeArray<BSTR> file;
		if (temp.second) {
			file.Add(CComBSTR(L"true"));
			file.Add(CComBSTR(temp.first.c_str()));
		}
		else {
			file.Add(CComBSTR(L"false"));
		}
		CComVariant out(file);
		result->vt = VT_EMPTY;
		out.Detach(result);
	}
	return S_OK;
}


STDMETHODIMP CFileMgrComObj::setFM()
{
	// TODO: Add your implementation code here
	fm = new FileMgr();
	set = true;
	return S_OK;
}
