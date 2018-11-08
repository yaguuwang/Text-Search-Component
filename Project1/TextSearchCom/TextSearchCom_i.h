

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for TextSearchCom.idl:
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

#ifndef __TextSearchCom_i_h__
#define __TextSearchCom_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITextSearchComObj_FWD_DEFINED__
#define __ITextSearchComObj_FWD_DEFINED__
typedef interface ITextSearchComObj ITextSearchComObj;

#endif 	/* __ITextSearchComObj_FWD_DEFINED__ */


#ifndef __TextSearchComObj_FWD_DEFINED__
#define __TextSearchComObj_FWD_DEFINED__

#ifdef __cplusplus
typedef class TextSearchComObj TextSearchComObj;
#else
typedef struct TextSearchComObj TextSearchComObj;
#endif /* __cplusplus */

#endif 	/* __TextSearchComObj_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ITextSearchComObj_INTERFACE_DEFINED__
#define __ITextSearchComObj_INTERFACE_DEFINED__

/* interface ITextSearchComObj */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITextSearchComObj;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("906f80e3-2310-4615-99f1-5b34d2d59ed3")
    ITextSearchComObj : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE search( 
            /* [in] */ BSTR file,
            /* [in] */ BSTR pattern,
            /* [retval][out] */ VARIANT *results) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE setTS( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITextSearchComObjVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITextSearchComObj * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITextSearchComObj * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITextSearchComObj * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITextSearchComObj * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITextSearchComObj * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITextSearchComObj * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITextSearchComObj * This,
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
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *search )( 
            ITextSearchComObj * This,
            /* [in] */ BSTR file,
            /* [in] */ BSTR pattern,
            /* [retval][out] */ VARIANT *results);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *setTS )( 
            ITextSearchComObj * This);
        
        END_INTERFACE
    } ITextSearchComObjVtbl;

    interface ITextSearchComObj
    {
        CONST_VTBL struct ITextSearchComObjVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITextSearchComObj_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITextSearchComObj_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITextSearchComObj_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITextSearchComObj_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITextSearchComObj_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITextSearchComObj_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITextSearchComObj_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITextSearchComObj_search(This,file,pattern,results)	\
    ( (This)->lpVtbl -> search(This,file,pattern,results) ) 

#define ITextSearchComObj_setTS(This)	\
    ( (This)->lpVtbl -> setTS(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITextSearchComObj_INTERFACE_DEFINED__ */



#ifndef __TextSearchComLib_LIBRARY_DEFINED__
#define __TextSearchComLib_LIBRARY_DEFINED__

/* library TextSearchComLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_TextSearchComLib;

EXTERN_C const CLSID CLSID_TextSearchComObj;

#ifdef __cplusplus

class DECLSPEC_UUID("82040f21-3232-4269-a575-c5cd708df823")
TextSearchComObj;
#endif
#endif /* __TextSearchComLib_LIBRARY_DEFINED__ */

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


