#include <iostream>
#include <vector>
#include "task3.cpp"
using namespace std;

void printResult(const vector<int>& result) {
    cout << "[ ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << "]" << endl;
}

int main() {

    // Test 1: Multiple occurrences
    vector<int> arr1 = {5, 2, 5, 8, 5};
    cout << "Test 1: ";
    printResult(findAllIndices(arr1, 5));

    // Test 2: Key not present
    vector<int> arr2 = {1, 2, 3, 4};
    cout << "Test 2: ";
    printResult(findAllIndices(arr2, 9));

    // Test 3: Empty array
    vector<int> arr3;
    cout << "Test 3: ";
    printResult(findAllIndices(arr3, 5));

    return 0;
}