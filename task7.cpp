#include <vector>
using namespace std;

using Matrix = vector<vector<int>>;

Matrix addMatrix(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];

    return C;
}

Matrix subtractMatrix(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];

    return C;
}

Matrix naiveMultiply(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];

    return C;
}

Matrix strassenMultiply(const Matrix& A, const Matrix& B) {

    int n = A.size();

    if (n <= 2) {
        return naiveMultiply(A, B);
    }

    int half = n / 2;

    Matrix A11(half, vector<int>(half));
    Matrix A12(half, vector<int>(half));
    Matrix A21(half, vector<int>(half));
    Matrix A22(half, vector<int>(half));

    Matrix B11(half, vector<int>(half));
    Matrix B12(half, vector<int>(half));
    Matrix B21(half, vector<int>(half));
    Matrix B22(half, vector<int>(half));

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {

            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    Matrix M1 = strassenMultiply(
        addMatrix(A11, A22),
        addMatrix(B11, B22)
    );

    Matrix M2 = strassenMultiply(
        addMatrix(A21, A22),
        B11
    );

    Matrix M3 = strassenMultiply(
        A11,
        subtractMatrix(B12, B22)
    );

    Matrix M4 = strassenMultiply(
        A22,
        subtractMatrix(B21, B11)
    );

    Matrix M5 = strassenMultiply(
        addMatrix(A11, A12),
        B22
    );

    Matrix M6 = strassenMultiply(
        subtractMatrix(A21, A11),
        addMatrix(B11, B12)
    );

    Matrix M7 = strassenMultiply(
        subtractMatrix(A12, A22),
        addMatrix(B21, B22)
    );

    Matrix C11 = addMatrix(
        subtractMatrix(addMatrix(M1, M4), M5),
        M7
    );

    Matrix C12 = addMatrix(M3, M5);

    Matrix C21 = addMatrix(M2, M4);

    Matrix C22 = addMatrix(
        subtractMatrix(addMatrix(M1, M3), M2),
        M6
    );

    Matrix C(n, vector<int>(n));

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {

            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }

    return C;
}