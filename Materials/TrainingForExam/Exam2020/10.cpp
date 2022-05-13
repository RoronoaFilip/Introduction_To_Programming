#include <iostream>
using namespace std;
int **mergearrays(int *arr1, int *arr2, int m) {
    int **finalArr = new int *[2];
    for (int i = 0; i < 2; ++i) {
        finalArr[i] = new int[m];
    }
    if (arr1 == nullptr || arr2 == nullptr) {
        finalArr[0][0] = -1;
        return finalArr;
    }
    for (int i = 0; i < m; ++i) {
        finalArr[0][i] = arr1[i];
    }
    for (int i = 0; i < m; ++i) {
        finalArr[1][i] = arr2[i];
    }
    return finalArr;
}
int main() {
    int a;
    int A[50] = {3, 5, 11, 2, 9};
    int B[50] = {1, 4, 32, 71, 5};
    int m = 5;
    int **ptr = mergearrays(A, B, m);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ptr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}