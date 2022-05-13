#include <iostream>
using namespace std;
int *countletters(int arr1[], int arr2[], int N) {
    int *result = new int[2];
    result[0] = 0;
    result[1] = 0;
    for (int i = 0; i < N; ++i) {
        if ((arr1[i] + arr2[i]) >= 65 && (arr1[i] + arr2[i]) <= 90) {
            ++result[0];
        } else if ((arr1[i] + arr2[i]) >= 97 && (arr1[i] + arr2[i]) <= 122) {
            ++result[1];
        }
    }
    return result;
}

int main() {
    int arr1[50] = {};
    int arr2[50] = {};
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr1[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> arr2[i];
    }
    int *result = countletters(arr1, arr2, N);
    cout << result[0] << "," << result[1];
    return 0;
}