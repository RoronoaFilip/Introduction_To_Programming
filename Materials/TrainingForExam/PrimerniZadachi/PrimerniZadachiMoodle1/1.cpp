#include <iostream>
using namespace std;

//Да се напише функция на C++, която приема като параметър два едномерни сортирани целочислени масива с елементи
// от тип int и връща като резултат трети масив (който съдържа всички елементи на двата масива и само тях),
// който също е сортиран. Предполага се, че входните масиви са сортирани преди да се извика написаната от вас функция.

int *sortArr(int arr1[], int arr2[], int n, int m) {
    int *sortedArr = new int[50];
    for (int i = 0; i < n; i++) {
        sortedArr[i] = arr1[i];
    }
    int sum = n + m;
    int index = 0;
    for (int i = n; i < sum; i++) {
        sortedArr[i] = arr2[index];
        ++index;
    }

    if (arr1[0] <= arr1[1]) {
        for (int i = 0; i < sum; ++i) {
            for (int j = i + 1; j < sum; j++) {
                if (sortedArr[i] > sortedArr[j]) {
                    int swap = sortedArr[i];
                    sortedArr[i] = sortedArr[j];
                    sortedArr[j] = swap;
                }
            }
        }
    } else if (arr1[0] > arr1[1]) {
        for (int i = 0; i < sum; ++i) {
            for (int j = i + 1; j < sum; j++) {
                if (sortedArr[i] < sortedArr[j]) {
                    int swap = sortedArr[i];
                    sortedArr[i] = sortedArr[j];
                    sortedArr[j] = swap;
                }
            }
        }
    }

    return sortedArr;
}

int main() {
    int arr[50] = {};
    int arr2[50] = {};
    int n;
    int m;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    int *sortedArr = sortArr(arr, arr2, n, m);
    for (int i = 0; i < n + m; ++i) {
        cout << sortedArr[i];
    }
    return 0;
}