#include <iostream>

// Enable memory leak detection
#define _CRTDBG_MAP_ALLOC #include <crtdbg.h>

using namespace std;

int main()
{
    string* username;
    username = new string;
    *username = "john";

    username = new string;
    *username = "nashid";

    delete(username);

    _CrtDumpMemoryLeaks();

}
