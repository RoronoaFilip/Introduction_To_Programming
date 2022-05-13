#include <iostream>
using namespace std;
void sortArrAscending(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void sortArrDescending(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main() {
    int arr[50] = {};
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sortArrAscending(arr, n);

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    cout << endl;
    sortArrDescending(arr, n);

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}