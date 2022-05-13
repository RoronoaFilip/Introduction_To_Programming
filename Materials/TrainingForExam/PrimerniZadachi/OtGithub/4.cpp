#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <winspool.h>
using namespace std;

int aboveDiagonal(int **matrix, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int belowDiagonal(int **matrix, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            sum += matrix[j][i];
        }
    }
    return sum;
}

int mainDiagonal(int **matrix, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += matrix[i][i];
    }
    return sum;
}

int secondDiagonal(int **matrix, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += matrix[n - i - 1][n - i - 1];
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    int **matrix = new int *[50];
    for (int i = 0; i < 50; ++i) {
        matrix[i] = new int[50];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << mainDiagonal(matrix, n);

    for (int i = 0; i < 50; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    Sleep(100000);
    return 0;
}