#ifndef _EASYCKL
#define _EASYCKL
#define CKLEXPORT extern "C" 

#ifndef  __ECKL_SRC_DEV_
typedef struct tagRBUTTON_DOWN_INFOMATION {
	SIZE_T cbSzie;
	int Flag;
	void* pFrame;
	const wchar_t* SelectionText;
	const wchar_t* LinkUrl;
	const wchar_t* SourceUrl;
	void* Retention;
}RBUTTON_DOWN_INFOMATION, *LPRBUTTON_DOWN_INFOMATION;

// No node is selected.
#define MENU_TYPEFLAG_NONE 0
// The top page is selected.
#define MENU_TYPEFLAG_PAGE 1 << 0
// A subframe page is selected.
#define MENU_TYPEFLAG_FRAME 1 << 1
// A link is selected.
#define MENU_TYPEFLAG_LINK 1 << 2
// A media node is selected.
#define MENU_TYPEFLAG_MEDIA 1 << 3
// There is a textual or mixed selection that is selected.
#define MENU_TYPEFLAG_SELECTION 1 << 4
// An editable element is selected.
#define MENU_TYPEFLAG_EDITABLE 1 << 5

#endif // __ECKL_SRC_DEV_

typedef BOOL(WINAPI * V8Handler_CallBack)(const wchar_t* name, const void* argu, void* retval);
typedef void(WINAPI * Chrome_CallBack_V8)(void* context);
typedef void(WINAPI * Chrome_CallBack_BrowserCreated)(DWORD id, void* browser);
typedef void(WINAPI * Chrome_CallBack_Error)(DWORD id, const wchar_t* url, BOOL isCertError);
typedef void(WINAPI * Chrome_CallBack_ChUrl)(DWORD id, const wchar_t* url);
typedef void(WINAPI * Chrome_CallBack_Download)(DWORD id, const wchar_t* url);
typedef BOOL(WINAPI * Chrome_CallBack_NewWindow)(DWORD id, const wchar_t* url, const wchar_t* current_window_url);
typedef BOOL(WINAPI * Chrome_CallBack_ChState)(DWORD id, BOOL isLoading, BOOL canGoBack, BOOL canGoForward);
typedef void(WINAPI * Chrome_CallBack_JSDialog)(DWORD id, const wchar_t* msg);
typedef void(WINAPI * Chrome_CallBack_RButtonDown)(DWORD id, DWORD uMsg, LPRBUTTON_DOWN_INFOMATION info, DWORD not_used);
typedef void(WINAPI * Chrome_CallBack_ChTitle)(DWORD id, const wchar_t* text);
typedef bool(WINAPI * Chrome_CallBack_CanLoadUrl)(DWORD id, const wchar_t* url);

#ifndef  __ECKL_SRC_DEV_
typedef struct tagBROWSER_CALLBACKS {
	SIZE_T cbSzie;
	Chrome_CallBack_BrowserCreated created_callback;
	Chrome_CallBack_ChUrl churl_callback;
	Chrome_CallBack_NewWindow newwindow_callback;
	Chrome_CallBack_Download download_callback;
	Chrome_CallBack_ChState chstate_callback;
	Chrome_CallBack_JSDialog jsdialog_callback;
	Chrome_CallBack_Error error_callback;
	Chrome_CallBack_RButtonDown rbuttondown_callback;
	Chrome_CallBack_ChTitle chtitle_callback;
	Chrome_CallBack_CanLoadUrl canloadurl_callback;
}BROWSER_CALLBACKS, *LPBROWSER_CALLBACKS;

#define BROWSER_LASTERROR_LOADING 0x1
#define BROWSER_LASTERROR_LOADERROR 0x2
#define BROWSER_LASTERROR_LOADRESERROR 0x4
#define BROWSER_LASTERROR_CERTERROR 0x8
#endif // __ECKL_SRC_DEV_

CKLEXPORT BOOL WINAPI Chrome_IsUIThread();
CKLEXPORT int WINAPI Chrome_Initialize(HINSTANCE hInstance, BOOL nossl, BOOL cacheStorage);
CKLEXPORT int WINAPI Chrome_InitializeEx(HINSTANCE hInstance, DWORD flag, BOOL old_ver, wchar_t* local, wchar_t* cache_path);

#define BROWSERFLAG_SYNC 0x1
#define BROWSERFLAG_HEADER_REFERER 0x2
#define BROWSERFLAG_DISABLE_JAVASCRIPT 0x4
#define BROWSERFLAG_DISABLE_LOAD_IMAGE 0x8
#define BROWSERFLAG_DISABLE_WEB_SECURITY 0x10

CKLEXPORT void* WINAPI Chrome_CreateChildBrowser(DWORD flags, LPBROWSER_CALLBACKS callbacks, DWORD id, wchar_t* referer, wchar_t* url, HWND hParent, RECT* rect, void* notused);

CKLEXPORT void* WINAPI Chrome_CreateBrowserSyncWithReferer(wchar_t* referer, DWORD id, wchar_t* url, HWND hParent, RECT* rect,
	Chrome_CallBack_BrowserCreated created_callback, Chrome_CallBack_ChUrl churl_callback,
	Chrome_CallBack_NewWindow newwindow, Chrome_CallBack_Download download, Chrome_CallBack_ChState chstate,
	Chrome_CallBack_JSDialog JSDialog, Chrome_CallBack_Error error, Chrome_CallBack_RButtonDown rbuttondown,
	Chrome_CallBack_ChTitle chtitle, Chrome_CallBack_CanLoadUrl canloadurl, void* rev);

CKLEXPORT void* WINAPI Chrome_CreateBrowserExWithReferer(wchar_t* referer, DWORD id, wchar_t* url, HWND hParent, RECT* rect,
	Chrome_CallBack_BrowserCreated created_callback, Chrome_CallBack_ChUrl churl_callback,
	Chrome_CallBack_NewWindow newwindow, Chrome_CallBack_Download download, Chrome_CallBack_ChState chstate,
	Chrome_CallBack_JSDialog JSDialog, Chrome_CallBack_Error error, Chrome_CallBack_RButtonDown rbuttondown,
	Chrome_CallBack_ChTitle chtitle, Chrome_CallBack_CanLoadUrl canloadurl, void* rev);

CKLEXPORT void* WINAPI Chrome_CreateBrowserSync(DWORD id, wchar_t* url, HWND hParent, RECT* rect,
	Chrome_CallBack_BrowserCreated created_callback, Chrome_CallBack_ChUrl churl_callback,
	Chrome_CallBack_NewWindow newwindow, Chrome_CallBack_Download download, Chrome_CallBack_ChState chstate,
	Chrome_CallBack_JSDialog JSDialog, Chrome_CallBack_Error error, Chrome_CallBack_RButtonDown rbuttondown,
	Chrome_CallBack_ChTitle chtitle, Chrome_CallBack_CanLoadUrl canloadurl, void* rev);

CKLEXPORT void WINAPI Chrome_CreateBrowserEx(DWORD id, wchar_t* url, HWND hParent, RECT* rect,
	Chrome_CallBack_BrowserCreated created_callback, Chrome_CallBack_ChUrl churl_callback,
	Chrome_CallBack_NewWindow newwindow, Chrome_CallBack_Download download, Chrome_CallBack_ChState chstate,
	Chrome_CallBack_JSDialog JSDialog, Chrome_CallBack_Error error, Chrome_CallBack_RButtonDown rbuttondown,
	Chrome_CallBack_ChTitle chtitle, Chrome_CallBack_CanLoadUrl canloadurl, void* rev);

CKLEXPORT void WINAPI Chrome_CreateBrowser(DWORD id, wchar_t* url, HWND hParent, RECT* rect,
	Chrome_CallBack_BrowserCreated created_callback, Chrome_CallBack_ChUrl churl_callback,
	Chrome_CallBack_NewWindow newwindow, Chrome_CallBack_Download download, Chrome_CallBack_ChState chstate,
	Chrome_CallBack_JSDialog JSDialog, Chrome_CallBack_Error error, Chrome_CallBack_RButtonDown rbuttondown);

CKLEXPORT void WINAPI Chrome_MessageLoop();
CKLEXPORT void WINAPI Chrome_Shutdown();
CKLEXPORT void WINAPI Chrome_SetUserAgent(const wchar_t* ua);
CKLEXPORT void WINAPI Chrome_SetProxyServer(const wchar_t* proxy);
CKLEXPORT void WINAPI Chrome_LoadUrl(void* browser, const wchar_t* url);
CKLEXPORT HWND WINAPI Chrome_Window(void* browser);
CKLEXPORT void WINAPI Chrome_GoBack(void* browser);
CKLEXPORT void WINAPI Chrome_GoForward(void* browser);
CKLEXPORT void WINAPI Chrome_Refresh(void* browser);
CKLEXPORT void WINAPI Chrome_Stop(void* browser);
CKLEXPORT void WINAPI Chrome_ExecJS(void* browser, const wchar_t* js);
CKLEXPORT void WINAPI Chrome_EnableCookieStorageEx(const wchar_t* CookiePath);
CKLEXPORT void WINAPI Chrome_EnableCookieStorage();
CKLEXPORT void WINAPI Chrome_DisableCookieStorage();
CKLEXPORT void WINAPI Chrome_CookieManagerFlushStore();
CKLEXPORT void WINAPI Chrome_Close(void* browser);
CKLEXPORT void WINAPI Chrome_SetV8ContextCallback(Chrome_CallBack_V8 contextcreate, V8Handler_CallBack handler);
CKLEXPORT void WINAPI Chrome_SetOSModalLoop(bool osModalLoop);
CKLEXPORT DWORD WINAPI Chrome_GetUrlLength(void* browser);
CKLEXPORT void WINAPI Chrome_GetUrlString(void* browser, wchar_t* buffer, DWORD buffer_length);
CKLEXPORT void WINAPI Chrome_DoMessageLoopWork();
CKLEXPORT void WINAPI Chrome_LoadString(void* browser, const wchar_t* string, const wchar_t* url);
CKLEXPORT HWND WINAPI Chrome_GetWindowHandle(void* browser);
CKLEXPORT void WINAPI Chrome_EnableSystemFlash();
CKLEXPORT void WINAPI Chrome_LoadFlashPlugin(wchar_t* ppapi_flash_path, wchar_t* ppapi_flash_version);
CKLEXPORT void WINAPI Chrome_ShowDevTools(void* browser);
CKLEXPORT void WINAPI Chrome_SetUserDataLongPtr(void* browser, LONG_PTR data);

enum BrowserInfomationType
{
	BrowserInfomationUserDataLoogPtr = 0,
	BrowserInfomationCanGoBack = 1,
	BrowserInfomationCanGoForward = 2,
	BrowserInfomationMainFrame = 3,
	BrowserInfomationIsLoading = 4,
	BrowserInfomationLastError = 5
};

CKLEXPORT void WINAPI Chrome_QueryBrowserInfomation(void* browser, BrowserInfomationType type, void* buffer);

CKLEXPORT int WINAPI EcKeInitialize(HINSTANCE hInstance, DWORD flag, wchar_t* local, wchar_t* cache_path, void* recvd);
CKLEXPORT void WINAPI EcKeCookieStorageControl(BOOL enable, wchar_t* CookiePath, bool persist_session_cookies);

#ifndef __EC_PACK_API_CPP_
CKLEXPORT void WINAPI EcPkHtmlRefreshContentJumpUrl(void* handler, wchar_t* url, wchar_t* referer);
CKLEXPORT void WINAPI EcPkJavaScriptSetValueByObjectId(void* handler, wchar_t* id, wchar_t* value);
CKLEXPORT void WINAPI EcPkJavaScriptSetValueByObjectName(void* handler, wchar_t* name, wchar_t* value);
CKLEXPORT void WINAPI EcPkJavaScriptSubmitByFormId(void* handler, wchar_t* id);
CKLEXPORT void WINAPI EcPkJavaScriptSubmitByFormName(void* handler, wchar_t* name);
CKLEXPORT void* WINAPI EcPkCreateJSRefererBrowserSync(DWORD id, HWND hParent, RECT* rect, wchar_t* url, wchar_t* referer, LPBROWSER_CALLBACKS callbacks);
#endif // __EC_PACK_API_CPP_

#ifndef  __EC_CUSTOMIZE_JS_CPP_
CKLEXPORT void WINAPI Chrome_AddJSFunction(void* context, wchar_t* name);
CKLEXPORT DWORD WINAPI Chrome_GetV8ValueListSize(const void* arguments);
CKLEXPORT DWORD WINAPI Chrome_GetV8ValueInt(const void* arguments, size_t pos);
CKLEXPORT DWORD WINAPI Chrome_GetV8ValueStringLength(const void* arguments, size_t pos);
CKLEXPORT void WINAPI Chrome_GetV8ValueString(const void* arguments, size_t pos, wchar_t* buffer, size_t buffer_length);
CKLEXPORT void WINAPI Chrome_SetV8ReturnValueInt(const void* lpretval, int value);
CKLEXPORT void WINAPI Chrome_SetV8ReturnValueString(const void* lpretval, wchar_t* value);
#endif // __EC_CUSTOMIZE_JS_CPP_

#ifndef  __EC_FRAME_API_CPP_
CKLEXPORT void WINAPI Chrome_FrameLoadUrl(void* frame, wchar_t* url);
CKLEXPORT void WINAPI Chrome_FrameLoadString(void* frame, wchar_t* string, wchar_t* url);
CKLEXPORT bool WINAPI Chrome_FrameIsMain(void* frame);
CKLEXPORT void WINAPI Chrome_ReleaseFrame(void* frame);
CKLEXPORT void* WINAPI Chrome_GetNameFrame(void* browser, wchar_t* name);
CKLEXPORT void* WINAPI EcQBIGetMainFrame(void* browser);
CKLEXPORT void WINAPI Chrome_FrameDoCopy(void* frame);
CKLEXPORT void WINAPI Chrome_FrameDoCut(void* frame);
CKLEXPORT void WINAPI Chrome_FrameDoDelete(void* frame);
CKLEXPORT void WINAPI Chrome_FrameDoPaste(void* frame);
#endif // __EC_FRAME_API_CPP_

#ifdef  __ECKL_SRC_DEV_
void _ECKL_CopyWString(CefString source, wchar_t* buffer, size_t buffer_length);
#endif // __ECKL_SRC_DEV_

#endif