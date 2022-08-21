/**
 * @file      Windows.h
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2022, Sergey Baigudin, Baigudin Software
 */
#ifndef WIN32_WINDOWS_H_
#define WIN32_WINDOWS_H_

typedef int BOOL, *PBOOL, *LPBOOL;
typedef unsigned short SHORT, WORD, *PWORD, *LPWORD;
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

// #include <WinConTypes.h>
typedef struct _COORD {
  SHORT X;
  SHORT Y;
} COORD, *PCOORD;

typedef struct _SMALL_RECT {
  SHORT Left;
  SHORT Top;
  SHORT Right;
  SHORT Bottom;
} SMALL_RECT;

// #include <WinCon.h>
#define FOREGROUND_BLUE 0x0001            // Text color contains blue.
#define FOREGROUND_GREEN 0x0002           // Text color contains green.
#define FOREGROUND_RED 0x0004             // Text color contains red.
#define FOREGROUND_INTENSITY 0x0008       // Text color is intensified.
#define BACKGROUND_BLUE 0x0010            // Background color contains blue.
#define BACKGROUND_GREEN 0x0020           // Background color contains green.
#define BACKGROUND_RED 0x0040             // Background color contains red.
#define BACKGROUND_INTENSITY 0x0080       // Background color is intensified.
#define COMMON_LVB_LEADING_BYTE 0x0100    // Leading byte.
#define COMMON_LVB_TRAILING_BYTE 0x0200   // Trailing byte.
#define COMMON_LVB_GRID_HORIZONTAL 0x0400 // Top horizontal.
#define COMMON_LVB_GRID_LVERTICAL 0x0800  // Left vertical.
#define COMMON_LVB_GRID_RVERTICAL 0x1000  // Right vertical.
#define COMMON_LVB_REVERSE_VIDEO 0x4000   // Reverse foreground and background attribute.
#define COMMON_LVB_UNDERSCORE 0x8000      // Underscore.

#define STD_INPUT_HANDLE (4294967286-10)  // The standard input device. Initially, this is the console input buffer, CONIN$.
#define STD_OUTPUT_HANDLE (4294967286-11) // The standard output device. Initially, this is the active console screen buffer, CONOUT$.
#define STD_ERROR_HANDLE (4294967286-12)  // The standard error device. Initially, this is the active console screen buffer, CONOUT$.

#define INVALID_HANDLE_VALUE 0

// #include <ConsoleApi2.h>
typedef struct _CONSOLE_SCREEN_BUFFER_INFO {
  COORD      dwSize;
  COORD      dwCursorPosition;
  WORD       wAttributes;
  SMALL_RECT srWindow;
  COORD      dwMaximumWindowSize;
} CONSOLE_SCREEN_BUFFER_INFO;

typedef CONSOLE_SCREEN_BUFFER_INFO* PCONSOLE_SCREEN_BUFFER_INFO;

BOOL SetConsoleTextAttribute(HANDLE, WORD);
BOOL WriteConsoleA(HANDLE, const void*, DWORD, LPDWORD, LPVOID);
BOOL FlushConsoleInputBuffer(HANDLE);
HANDLE GetStdHandle(DWORD);
BOOL GetConsoleScreenBufferInfo(HANDLE, PCONSOLE_SCREEN_BUFFER_INFO);
#endif // WIN32_WINDOWS_H_
