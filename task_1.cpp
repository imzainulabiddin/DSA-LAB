#include <iostream>
using namespace std;

int main()
{
    int val = 12;
    int *ptr = &val;


    cout << "Value of the integer: " << val
         << "\nValue of the pointer: " << *ptr
         << "\nAfter modifying the value through the pointer: *ptr = 20\n";
    
    *ptr = 20;

    cout << "Interger: " << val;
    cout << "\nPointer: " << *ptr;


    return 0;

}