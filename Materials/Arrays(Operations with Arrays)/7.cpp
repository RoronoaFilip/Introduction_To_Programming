#include <iostream>
#include <vector>

using namespace std;
// Дадена е квадратна реална матрица А с размерност nxn . Да се състави програма, която намира сумата от елементите под главния диагонал (включително главният диагонал).
int main() {
    const int size = 50;
    int arr[size][size];
    
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
        }
    }

    int sum = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = size - 1 - i; j < N; ++j) {
            sum += arr[i][j];
        }
    }
    cout << sum << endl;

    return 0;
} 