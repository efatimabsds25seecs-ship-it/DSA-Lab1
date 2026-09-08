#include <vector>
#include <unordered_map>
using namespace std;

int findMode(const vector<int>& arr) {

    if (arr.empty()) {
        return -1;
    }

    unordered_map<int, int> frequency;

    for (int value : arr) {
        frequency[value]++;
    }

    int mode = arr[0];
    int maxFrequency = frequency[mode];

    for (int value : arr) {
        if (frequency[value] > maxFrequency) {
            maxFrequency = frequency[value];
            mode = value;
        }
    }

    return mode;
}