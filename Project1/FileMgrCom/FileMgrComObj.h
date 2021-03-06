//////////////////////////////////////////////////////////////
// FileMgrComObj.h : Declaration of the CFileMgrComObj      //
// ver 1.0                                                  //
// Haoyu Wang, CSE775 - Distributed Object, Spring 2018     //
//////////////////////////////////////////////////////////////
/*
* Module Operations:
* ------------------
* FileMgrComObj is an in-process COM component that provides the interfaces
* that talk to a FileMgr instance.
*
* Public Interface:
* -----------------
* STDMETHOD(setFM)();
* - create a FileMgr instance
* STDMETHOD(setPath)(BSTR path);
* - set path for created obj
* STDMETHOD(setPatterns)(VARIANT* patterns);
* - set searching pattern with given variant
* STDMETHOD(scan)();
* - perform scan process after setting path and patterns
* STDMETHOD(get)(VARIANT* result);
* - get result back which contains a success code and filename.
* - when file exist result should be {"true", "filename"}
* - when no more file to return, result should be {"false", ""}
*
* Required Files:
* ---------------
* FileMgr.h
* FileMgrCom_i.h
*
* Maintenance History:
* --------------------
* ver 1.0 : 03 Apr 2017
* - first release
*
*/

#pragma once
#include "resource.h"       // main symbols
#include "../FileMgr/FileMgr.h"
#include "FileMgrCom_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CFileMgrComObj

class ATL_NO_VTABLE CFileMgrComObj :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFileMgrComObj, &CLSID_FileMgrComObj>,
	public IDispatchImpl<IFileMgrComObj, &IID_IFileMgrComObj, &LIBID_FileMgrComLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CFileMgrComObj()
	{
	}

DECLARE_REGISTRY_RESOURCEID(106)


BEGIN_COM_MAP(CFileMgrComObj)
	COM_INTERFACE_ENTRY(IFileMgrComObj)
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
	FileMgr * fm;
	bool set = false;

	inline std::string BSTR2STDSTR(const BSTR bstr, int cp = CP_UTF8) {
		std::wstring ws(bstr);
		std::string stdstr(ws.begin(), ws.end());
		return stdstr;
	}

public:

	STDMETHOD(setPath)(BSTR path);
	STDMETHOD(scan)();
	STDMETHOD(setPatterns)(VARIANT* patterns);
	STDMETHOD(get)(VARIANT* result);
	STDMETHOD(setFM)();
};

OBJECT_ENTRY_AUTO(__uuidof(FileMgrComObj), CFileMgrComObj)
