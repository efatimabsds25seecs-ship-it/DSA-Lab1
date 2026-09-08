#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "task7.cpp"

using namespace std;

void printMatrix(const Matrix& A) {
    for (const auto& row : A) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

bool matricesEqual(const Matrix& A, const Matrix& B) {
    return A == B;
}

int main() {

    // Test 1: 2x2
    Matrix A2 = {
        {1, 2},
        {3, 4}
    };

    Matrix B2 = {
        {5, 6},
        {7, 8}
    };

    Matrix result2 = strassenMultiply(A2, B2);
    Matrix expected2 = naiveMultiply(A2, B2);

    cout << "2x2 Test: "
         << (matricesEqual(result2, expected2) ? "PASS" : "FAIL")
         << endl;

    // Test 2: 4x4
    Matrix A4 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    Matrix B4 = {
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };

    Matrix result4 = strassenMultiply(A4, B4);
    Matrix expected4 = naiveMultiply(A4, B4);

    cout << "4x4 Test: "
         << (matricesEqual(result4, expected4) ? "PASS" : "FAIL")
         << endl;

    // Test 3: Random 4x4 matrices
    srand(42);

    Matrix R1(4, vector<int>(4));
    Matrix R2(4, vector<int>(4));

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            R1[i][j] = rand() % 10;
            R2[i][j] = rand() % 10;
        }
    }

    Matrix strassenResult = strassenMultiply(R1, R2);
    Matrix naiveResult = naiveMultiply(R1, R2);

    cout << "Random 4x4 Test: "
         << (matricesEqual(strassenResult, naiveResult)
             ? "PASS" : "FAIL")
         << endl;

    return 0;
}