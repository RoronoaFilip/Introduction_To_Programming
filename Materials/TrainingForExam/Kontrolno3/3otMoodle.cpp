#include <iostream>
using namespace std;

double returnSumOfIndexes(double arr[], int index) {
    double sum = 0;
    for (int i = 0; i < index; i++) {
        if (i % 2 != 0) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    const int SIZE = 50;
    double nums1[SIZE] = {4.7};
    double nums3[SIZE] = {2.5, 6.3, 8.6};
    double numsN[SIZE] = {};

    for (int i = 0; i < n; i++) {
        cin >> numsN[i];
    }
    cout << returnSumOfIndexes(nums1, 1) << " " << returnSumOfIndexes(nums3, 3) << " " << returnSumOfIndexes(numsN, n);

    return 0;
}