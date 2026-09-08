#include <iostream>
#include "task4.cpp"
using namespace std;

int main() {

    cout << "Beginning: "
         << findPattern("hello world", "hello") << endl;

    cout << "End: "
         << findPattern("hello world", "world") << endl;

    cout << "Not present: "
         << findPattern("hello world", "xyz") << endl;

    cout << "Empty pattern: "
         << findPattern("hello world", "") << endl;

    return 0;
}