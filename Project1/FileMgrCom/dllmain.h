// dllmain.h : Declaration of module class.

class CFileMgrComModule : public ATL::CAtlDllModuleT< CFileMgrComModule >
{
public :
	DECLARE_LIBID(LIBID_FileMgrComLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_FILEMGRCOM, "{fd6ebcab-fbaf-4e69-80ca-80319f7c7e66}")
};

extern class CFileMgrComModule _AtlModule;
