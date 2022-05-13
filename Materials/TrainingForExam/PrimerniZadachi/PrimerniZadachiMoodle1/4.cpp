#include <iostream>
using namespace std;
//Да се напише функция на С++, която приема като параметри цяло число N и двумерна числова квадратна матрица
// с размери NxN и връща като резултат сумата на елементите над главния ѝ диагонал.

int sumAboveMainDiagonal(int n, int matrix[50][50]) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    int matrix[50][50] = {};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << sumAboveMainDiagonal(n, matrix);
    return 0;
}