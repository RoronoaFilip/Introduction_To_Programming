#include <iostream>
using namespace std;

//Да се напише функция на С++, която приема като параметри параметри цяло число N и
//двумерна числова квадратна матрица А с размери NxN и връща като резултат транспонираната матрица на А.

int **transpon(int N, int **A) {

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int swap = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = swap;
        }
    }
    int **result = A;
    return result;
}

int main() {
    int n;
    cin >> n;

    int **matrix = new int *[50];
    for (int i = 0; i < 50; i++) {
        matrix[i] = new int[50];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int **result = transpon(n, matrix);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }

    for (int i = 0; i < 50; i++) {
        delete[] matrix[i];
    }
    delete[] * matrix;

    for (int i = 0; i < 50; i++) {
        delete[] result[i];
    }
    delete[] result;
    return 0;
}