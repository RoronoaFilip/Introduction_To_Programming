#include <iostream>
using namespace std;

int returnMaxElement(int arr[], int index) {
    int max = arr[0];
    for (int i = 1; i < index; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}
int returnMinElement(int arr[], int index) {
    int min = arr[0];
    for (int i = 1; i < index; i++) {
        if (min > arr[i]) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int n;
    cin >> n;
    const int SIZE = 50;
    int nums[SIZE] = {};
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << returnMaxElement(nums, n);
    cout << " ";
    cout << returnMinElement(nums, n);
    return 0;
}