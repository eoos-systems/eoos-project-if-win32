/**
 * @file      Windows.h
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2022, Sergey Baigudin, Baigudin Software
 */
#ifndef WIN32_WINDOWS_H_
#define WIN32_WINDOWS_H_

typedef int BOOL, *PBOOL, *LPBOOL;
typedef unsigned short WORD, *PWORD, *LPWORD;
typedef unsigned int UINT;
typedef unsigned long DWORD, *PDWORD, *LPDWORD;
typedef long LONG, *PLONG, *LPLONG;
typedef void* HANDLE;
typedef const char* LPCSTR;
typedef void* LPVOID;
typedef unsigned long long ULONG_PTR;
typedef ULONG_PTR SIZE_T;
 
typedef DWORD (*LPTHREAD_START_ROUTINE)(LPVOID); 
 
// #include <winnt.h>
typedef struct _RTL_CRITICAL_SECTION 
{
} RTL_CRITICAL_SECTION, *PRTL_CRITICAL_SECTION;

// #include <winbase.h>
typedef struct _SECURITY_ATTRIBUTES 
{
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

typedef RTL_CRITICAL_SECTION CRITICAL_SECTION;
typedef CRITICAL_SECTION* LPCRITICAL_SECTION;

HANDLE CreateSemaphore(LPSECURITY_ATTRIBUTES, LONG, LONG, LPCSTR);

// #include <synchapi.h>
#define WAIT_OBJECT_0   0x00000000L
#define INFINITE        0xFFFFFFFF

void DeleteCriticalSection(LPCRITICAL_SECTION);
BOOL TryEnterCriticalSection(LPCRITICAL_SECTION);
void EnterCriticalSection(LPCRITICAL_SECTION);
void LeaveCriticalSection(LPCRITICAL_SECTION);
BOOL InitializeCriticalSectionAndSpinCount(LPCRITICAL_SECTION, DWORD);
DWORD WaitForSingleObject(HANDLE, DWORD);
BOOL ReleaseSemaphore(HANDLE, LONG, LPLONG);
void Sleep(DWORD);

// #include <handleapi.h>
BOOL CloseHandle(HANDLE hObject);

// #include <processthreadsapi.h>
HANDLE CreateThread(LPSECURITY_ATTRIBUTES, SIZE_T, LPTHREAD_START_ROUTINE, LPVOID, DWORD, LPDWORD);
DWORD ResumeThread(HANDLE hThread);
HANDLE GetCurrentProcess();
DWORD GetPriorityClass(HANDLE);
void ExitProcess(UINT);

#endif // WIN32_WINDOWS_H_
