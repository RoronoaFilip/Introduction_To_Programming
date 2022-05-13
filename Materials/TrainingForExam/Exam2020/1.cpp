#include <iostream>
using namespace std;
int AnalyzeArray(int arr[], int l) {
    if (l < 0 || arr == nullptr) {
        return -1;
    }
    int index = l - 1;
    int middleIndex = index / 2;
    int sum1 = 0;
    for (int i = 0; i <= middleIndex; ++i) {
        sum1 += arr[i];
    }
    int sum2 = 0;
    for (int i = middleIndex + 1; i <= index; ++i) {
        sum2 += arr[i];
    }
    return (sum1 == sum2) ? 1 : 0;
}
int main() {
    int arr[60] = {1, 6, 1, 0, 5, 199};
    int *arr1 = nullptr;
    cout << AnalyzeArray(arr, 6);
    return 0;
}