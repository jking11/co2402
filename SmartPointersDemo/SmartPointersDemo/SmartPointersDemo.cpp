/*
 *  Smart Pointer demonstration code
 *
 *  This code demonstrates how smart pointers are used in C++.
 *
 */

#include <iostream>
using namespace std;

int main()
{
    //
    //  Basic use of unique pointers
    //

    // Creating a unique pointer
    unique_ptr<int> banana(new int);
    //C++14 version: unique_ptr<int> banana = make_unique<int>();
    *banana = 13;
    cout << "banana created" << endl;
    cout << "banana: memory address " << banana << " value " << *banana << endl;
    cout << endl;

    // Pointing to a variable that another unique pointer is already pointing to
    unique_ptr<int> cherry;
    //cherry = banana;      // Compiler error: this is not allowed with unique pointers

    //
    //  Basic use of shared pointers
    //

    // Creating a shared pointer
    shared_ptr<int> hazelnut(new int);
    //C++14 format: shared_ptr<int> hazelnut = make_shared<int>();
    *hazelnut = 23;
    cout << "hazelnut created" << endl;
    cout << "hazelnut: memory address " << hazelnut << " value " << *hazelnut << endl;
    cout << endl;

    // Pointing to a variable that another unique pointer is already pointing to
    shared_ptr<int> jackfruit;
    jackfruit = hazelnut;
    cout << "jackfruit points to hazlenut" << endl;
    cout << "jackfruit: memory address " << jackfruit << " value " << *jackfruit << endl;
    cout << endl;

    //
    //  Destroying memory space
    //

    // Create new variable (i.e. allocate memory space)
    unique_ptr<int> damson(new int);
    *damson = 34;
    cout << "damson created" << endl;
    cout << "damson: memory address " << damson << " value " << *damson << endl;

    // Destroy variable (i.e. deallocate memory space) -- will also happen automatically when the program exits
    damson.reset();
    cout << "damson destroyed" << endl;
    cout << "damson: memory address " << damson << " value [read access error]" << endl;  // Note: trying to access *damson will now cause a runtime error
    cout << endl;


}

