#include <iostream>
#include <string>
#include <vector>
using namespace std;
int *arr(int *arr1, int *arr2, int size1, int size2) {
    int *result = new int[size1 + size2];
    int resultIndex = 0;
    int i = 0;
    int j = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            result[resultIndex] = arr1[i];
            ++i;
        } else {
            result[resultIndex] = arr2[j];
            ++j;
        }
        ++resultIndex;
    }
    while (i < size1) {
        result[resultIndex] = arr1[i];
        ++i;
        ++resultIndex;
    }
    while (j < size2) {
        result[resultIndex] = arr2[j];
        ++j;
        ++resultIndex;
    }
    return result;
}
int main() {
    int a;

    return 0;
}