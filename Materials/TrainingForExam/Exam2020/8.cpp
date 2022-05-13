#include <iostream>
using namespace std;
void ConvertArr(long arr[], long S, long E) {
    if (S < 0 || S > E) {
        return;
    }

    const int SIZE = 1000;
    long int flip[SIZE] = {};
    int flipIndex = 0;
    for (int i = S; i <= E; ++i) {
        flip[flipIndex] = arr[i];
        ++flipIndex;
    }

    int flipIndexCopy = flipIndex;
    for (int i = 0; i < flipIndex / 2; ++i) {
        int swap = flip[i];
        flip[i] = flip[flipIndexCopy - 1];
        flip[flipIndexCopy - 1] = swap;
        --flipIndexCopy;
    }

    int endIndex = 0;
    for (int i = S; i <= E; ++i) {
        arr[i] = flip[endIndex];
        ++endIndex;
    }
}
int main() {
    int n;
    cin >> n;
    long int arr[50000] = {};
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    long S = 2;
    long E = 5;
    ConvertArr(arr, S, E);
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
    }
    return 0;
}