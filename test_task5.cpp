#include <iostream>
#include "task5.cpp"
using namespace std;

void printTriangle(const vector<vector<int>>& triangle) {

    for (const auto& row : triangle) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main() {

    cout << "n = 0:" << endl;
    printTriangle(generatePascalsTriangle(0));

    cout << "\nn = 1:" << endl;
    printTriangle(generatePascalsTriangle(1));

    cout << "\nn = 5:" << endl;
    printTriangle(generatePascalsTriangle(5));

    return 0;
}