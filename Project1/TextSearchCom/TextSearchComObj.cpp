// TextSearchComObj.cpp : Implementation of CTextSearchComObj

#include "stdafx.h"
#include "TextSearchComObj.h"
#include <atlsafe.h>

// CTextSearchComObj



STDMETHODIMP CTextSearchComObj::search(BSTR file, BSTR pattern, VARIANT* results)
{
	// TODO: Add your implementation code here
	if (set) {
		auto temp = ts->search(BSTR2STDSTR(file), BSTR2STDSTR(pattern));
		CComSafeArray<int> lineNum;
		for (auto t : temp) lineNum.Add(t);
		lineNum.Add(-1);
		CComVariant out(lineNum);
		results->vt = VT_EMPTY;
		out.Detach(results);
	}
	return S_OK;
}


STDMETHODIMP CTextSearchComObj::setTS()
{
	// TODO: Add your implementation code here
	ts = new TextSearch();
	set = true;
	return S_OK;
}
