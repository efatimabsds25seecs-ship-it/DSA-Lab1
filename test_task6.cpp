#include <iostream>
#include <vector>
#include "task6.cpp"
using namespace std;

int main() {

    vector<int> arr1 = {1, 2, 2, 3, 4};
    cout << "Unique mode: " << findMode(arr1) << endl;

    vector<int> arr2 = {1, 1, 2, 2, 3};
    cout << "Multiple modes: " << findMode(arr2) << endl;

    vector<int> arr3;
    cout << "Empty array: " << findMode(arr3) << endl;

    return 0;
}