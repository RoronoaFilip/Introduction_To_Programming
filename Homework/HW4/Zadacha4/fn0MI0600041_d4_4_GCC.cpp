/**
 *
 * Solution to homework assignment 4
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2021/2022
 *
 * @author Filip Filchev
 * @idnumber 0MI0600041
 * @task 4
 * @compiler GCC
 *
 */
#include <iostream>
using namespace std;
bool isHacksaw(int *nums, int index, int i) {
    bool isTrue = true;
    if ((nums[i - 1] <= nums[i] && nums[i] <= nums[i + 1]) || (nums[i - 1] >= nums[i] && nums[i] >= nums[i + 1])) {
        return false;
    }
    if (i == index) {
        return true;
    } else {
        return isHacksaw(nums, index, ++i);
    }
}

int main() {
    int n;
    cin >> n;
    const int SIZE = 1000;
    int nums[SIZE] = {};
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    if (n < 3 || n > 1000) {
        cout << -1;
        return 0;
    }
    int startIndex = 1;
    int endIndex = n - 2;
    cout << ((isHacksaw(nums, endIndex, startIndex)) ? "yes" : "no");
    return 0;
}