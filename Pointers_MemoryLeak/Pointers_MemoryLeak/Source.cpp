/*
 *  Example showing how manual allocation of memory in C++ can lead to
 *  memory leaks.
 */

#include <iostream>

using namespace std;

// Enable memory leak detection
#define _CRTDBG_MAP_ALLOC #include <crtdbg.h>

int main()
{
    // Create a string pointer (i.e., variable holding the memory location of the first character of a string)
    string* username;

    // Point this at the memory allocated to a new (empty) string; copy the characters "john" to that memory location.
    username = new string;
    *username = "john";

    // Change this to point at the memory allocated to another new (empty) string; copy the characters "ranvir" to that memory location.
    username = new string;
    *username = "ranvir";

    // At this stage memory has been allocated for both "john" and "ranvir"; however, our pointer only links to "ranvir".

    // Deallocate the memory that we have a link for
    delete(username);

    // At this stage "ranvir" memory has been returned, but "john" is still in use.

    // Detect any memory leaks (i.e., "john")
    _CrtDumpMemoryLeaks();

}

