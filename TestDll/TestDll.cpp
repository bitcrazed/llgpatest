// TestDll.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "TestDll.h"
#include <string>
using namespace std;


// This is an example of an exported function.
TESTDLL_API int SayHello(wchar_t* dest, size_t destSize)
{
    const wstring greeting{ L"Hello!" };

    return wcscpy_s(dest, destSize, greeting.c_str());
}
