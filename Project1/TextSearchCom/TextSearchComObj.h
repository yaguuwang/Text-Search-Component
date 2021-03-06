//////////////////////////////////////////////////////////////
// TextSearchComObj.h : Declaration of the CTextSearchComObj//
// ver 1.0                                                  //
// Haoyu Wang, CSE775 - Distributed Object, Spring 2018     //
//////////////////////////////////////////////////////////////
/*
* Module Operations:
* ------------------
* TextSearchComObj is an in-process COM component that provides the interfaces
* that talk to a TextSearch instance.
*
* Public Interface:
* -----------------
* STDMETHOD(setTS)();
* - create a TextSearch instance
* STDMETHOD(search)(BSTR file, BSTR pattern, VARIANT* results);
* - search given file with regular expression and save result into results variant

* Required Files:
* ---------------
* TextSearch.h
* TextSearchCom_i.h
*
* Maintenance History:
* --------------------
* ver 1.0 : 03 Apr 2017
* - first release
*
*/

#pragma once
#include "resource.h"       // main symbols
#include "../TestSearch/TextSearch.h"
#include "TextSearchCom_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CTextSearchComObj

class ATL_NO_VTABLE CTextSearchComObj :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTextSearchComObj, &CLSID_TextSearchComObj>,
	public IDispatchImpl<ITextSearchComObj, &IID_ITextSearchComObj, &LIBID_TextSearchComLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CTextSearchComObj()
	{
	}

DECLARE_REGISTRY_RESOURCEID(106)


BEGIN_COM_MAP(CTextSearchComObj)
	COM_INTERFACE_ENTRY(ITextSearchComObj)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

private:
	TextSearch * ts;
	bool set = false;

	inline std::string BSTR2STDSTR(const BSTR bstr, int cp = CP_UTF8) {
		std::wstring ws(bstr);
		std::string stdstr(ws.begin(), ws.end());
		return stdstr;
	}

public:


	STDMETHOD(search)(BSTR file, BSTR pattern, VARIANT* results);
	STDMETHOD(setTS)();
};

OBJECT_ENTRY_AUTO(__uuidof(TextSearchComObj), CTextSearchComObj)
