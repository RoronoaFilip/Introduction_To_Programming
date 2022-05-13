#include <iostream>
using namespace std;

int returnSumOfIndexes(int arr[], int index) {
    int sum = 0;
    for (int i = 0; i < index; i++) {
        if (arr[i] % 2 == 0) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    const int SIZE = 50;
    int nums1[SIZE] = {3};
    int nums3[SIZE] = {3, 3, 1};
    int numsN[SIZE] = {};

    for (int i = 0; i < n; i++) {
        cin >> numsN[i];
    }
    cout << returnSumOfIndexes(nums1, 1) << " " << returnSumOfIndexes(nums3, 3) << " " << returnSumOfIndexes(numsN, n);

    return 0;
}