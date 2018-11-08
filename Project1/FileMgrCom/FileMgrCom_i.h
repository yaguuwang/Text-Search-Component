

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for FileMgrCom.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __FileMgrCom_i_h__
#define __FileMgrCom_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IFileMgrComObj_FWD_DEFINED__
#define __IFileMgrComObj_FWD_DEFINED__
typedef interface IFileMgrComObj IFileMgrComObj;

#endif 	/* __IFileMgrComObj_FWD_DEFINED__ */


#ifndef __FileMgrComObj_FWD_DEFINED__
#define __FileMgrComObj_FWD_DEFINED__

#ifdef __cplusplus
typedef class FileMgrComObj FileMgrComObj;
#else
typedef struct FileMgrComObj FileMgrComObj;
#endif /* __cplusplus */

#endif 	/* __FileMgrComObj_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IFileMgrComObj_INTERFACE_DEFINED__
#define __IFileMgrComObj_INTERFACE_DEFINED__

/* interface IFileMgrComObj */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IFileMgrComObj;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7e105776-a354-46e1-bf80-1cc8dd9dde72")
    IFileMgrComObj : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE setPath( 
            /* [in] */ BSTR path) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE scan( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE setPatterns( 
            /* [in] */ VARIANT *patterns) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE get( 
            /* [retval][out] */ VARIANT *result) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE setFM( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFileMgrComObjVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFileMgrComObj * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFileMgrComObj * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFileMgrComObj * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFileMgrComObj * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFileMgrComObj * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFileMgrComObj * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFileMgrComObj * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *setPath )( 
            IFileMgrComObj * This,
            /* [in] */ BSTR path);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *scan )( 
            IFileMgrComObj * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *setPatterns )( 
            IFileMgrComObj * This,
            /* [in] */ VARIANT *patterns);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *get )( 
            IFileMgrComObj * This,
            /* [retval][out] */ VARIANT *result);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *setFM )( 
            IFileMgrComObj * This);
        
        END_INTERFACE
    } IFileMgrComObjVtbl;

    interface IFileMgrComObj
    {
        CONST_VTBL struct IFileMgrComObjVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFileMgrComObj_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFileMgrComObj_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFileMgrComObj_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFileMgrComObj_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFileMgrComObj_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFileMgrComObj_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFileMgrComObj_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFileMgrComObj_setPath(This,path)	\
    ( (This)->lpVtbl -> setPath(This,path) ) 

#define IFileMgrComObj_scan(This)	\
    ( (This)->lpVtbl -> scan(This) ) 

#define IFileMgrComObj_setPatterns(This,patterns)	\
    ( (This)->lpVtbl -> setPatterns(This,patterns) ) 

#define IFileMgrComObj_get(This,result)	\
    ( (This)->lpVtbl -> get(This,result) ) 

#define IFileMgrComObj_setFM(This)	\
    ( (This)->lpVtbl -> setFM(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFileMgrComObj_INTERFACE_DEFINED__ */



#ifndef __FileMgrComLib_LIBRARY_DEFINED__
#define __FileMgrComLib_LIBRARY_DEFINED__

/* library FileMgrComLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_FileMgrComLib;

EXTERN_C const CLSID CLSID_FileMgrComObj;

#ifdef __cplusplus

class DECLSPEC_UUID("e1dae935-ffd2-4de3-a05d-423ad8eab7d8")
FileMgrComObj;
#endif
#endif /* __FileMgrComLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


