// LLGPATest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

using namespace std;

typedef errno_t (WINAPI* PSAYHELLOFN)(wchar_t*, size_t);

int main()
{
    wcout << L"Loading Test DLL ... ";

    HMODULE hLib = LoadLibrary(L"TestDll.dll");

    if (hLib != NULL)
    {
        wcout << L"SUCCESS!" << endl;
        
        PSAYHELLOFN pfn = (PSAYHELLOFN)GetProcAddress(hLib, "?SayHello@@YAHPEA_W_K@Z");
        if (pfn != NULL)
        {
            wcout << L"SUCCESS!";

            const int NUMCHARS = 512;
            wchar_t msg[NUMCHARS]{};

            pfn(msg, NUMCHARS-1);

            wcout << L" Greeting: \"" << msg << "\"" << endl;
        }
    }
    else
    {
        wcout << L"FAILED!" << endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
