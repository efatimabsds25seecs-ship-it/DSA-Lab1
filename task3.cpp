#include <iostream>
#include <vector>
using namespace std;

// Returns all indices where key occurs in the array.
vector<int> findAllIndices(const vector<int>& arr, int key) {
    vector<int> indices;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key) {
            indices.push_back(i);
        }
    }

    return indices;
}