/**
 *
 * Solution to homework assignment 3
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2021/2022
 *
 * @author Filip Filchev
 * @idnumber 0MI0600041
 * @task 2
 * @compiler GCC
 *
 */
#include <iostream>
using namespace std;
const int MAXSIZE = 100;
bool isTheNumberThere(const int num, const int arr[], const int arrSize, const int begin) {
    for (int i = begin + 1; i < arrSize; ++i) {
        if (arr[i] == num) {
            return true;
        }
    }
    return false;
}
int numberOfAppearances(const int num, const int arr[], const int arrSize, const int begin) {
    int count = 0;
    for (int i = begin + 1; i < arrSize; ++i) {
        if (arr[i] == num) {
            ++count;
        }
    }
    return count;
}
int maximumDistance(const int num, const int arr[], const int arrSize, const int begin) {
    int appearancesCount = numberOfAppearances(num, arr, arrSize, begin);
    int distance = 0;
    for (int i = begin + 1; i < arrSize; ++i) {
        ++distance;
        if (arr[i] == num) {
            --appearancesCount;
        }
        if (appearancesCount == 0) {
            break;
        }
    }
    return distance;
}
int longestDist(const int arr[], const int arrSize) {
    if (arrSize < 2) {
        return -2;
    }
    int index = arrSize - 1;
    bool isThere = false;
    int numbersOfDistances[MAXSIZE] = {};
    int numbersOfDistancesIndex = 0;
    int neededIndex = 0;
    for (int i = 0; i <= index; ++i) {
        isThere = isTheNumberThere(arr[i], arr, arrSize, i);
        if (isThere == true) {
            int maxDistance = maximumDistance(arr[i], arr, arrSize, i);
            numbersOfDistances[numbersOfDistancesIndex] = maxDistance;
        }
        ++numbersOfDistancesIndex;
    }

    int max = numbersOfDistances[0];
    for (int j = 1; j <= numbersOfDistancesIndex; ++j) {
        if (numbersOfDistances[j] > max) {
            max = numbersOfDistances[j];
            neededIndex = j;
        }
    }
    bool areAllDigitsZeros = true;
    for (int i = 0; i <= numbersOfDistancesIndex; ++i) {
        if (numbersOfDistances[i] != 0) {
            areAllDigitsZeros = false;
        }
    }
    if (areAllDigitsZeros == true) {
        return -1;
    }
    return neededIndex;
}
int main() {
    int n;
    cin >> n;
    if (n > 100) {
        cout << -1;
        return 0;
    }
    int index = n - 1;
    int nums[MAXSIZE] = {};
    for (int i = 0; i <= index; ++i) {
        cin >> nums[i];
    }
    int neededIndex = longestDist(nums, n);
    cout << neededIndex;
    return 0;
}