// dllmain.h : Declaration of module class.

class CTextSearchComModule : public ATL::CAtlDllModuleT< CTextSearchComModule >
{
public :
	DECLARE_LIBID(LIBID_TextSearchComLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_TEXTSEARCHCOM, "{060e9da1-5111-42a9-9c94-aa7acb1c3b5e}")
};

extern class CTextSearchComModule _AtlModule;
