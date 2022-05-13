#include <iostream>

using namespace std;

void findMinMax(int arr[][50], const int N, const int M, const bool isMin) {
    for (int i = 0; i < N; ++i) {
        int minMax = arr[i][0];
        for (int j = 1; j < M; ++j) {
            if (isMin) {
                if (minMax < arr[i][j]) {
                    minMax = arr[i][j];
                }
            } else {
                if (minMax > arr[i][j]) {
                    minMax = arr[i][j];
                }
            }
            
        }
        cout << minMax << " ";
    }
    cout << endl;
}

int main() {
    int arr[50][50];
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
        }
    }

    //     0 1 2
    //     -----
    // 0 | 1 2 3
    // 1 | 4 5 6
    findMinMax(arr, 50, 50, true);
    findMinMax(arr, 50, 50, false);


    return 0;
} 