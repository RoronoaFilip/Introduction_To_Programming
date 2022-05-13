#include <iostream>
using namespace std;

int *transformHoursMinutesSeconds(int n) {
    int *arr = new int[3];
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 0;
    while (n >= 60) {
        ++arr[1];
        n -= 60;
        if (arr[1] == 60) {
            ++arr[0];
            arr[1] = 0;
        }
    }

    arr[2] = n;
    return arr;
}

int main() {
    int n;
    cin >> n;
    int *time = transformHoursMinutesSeconds(n);

    if (time[0] >= 0 && time[0] < 10) {
        cout << 0 << time[0] << ":";

    } else {
        cout << time[0] << ":";
    }
    if (time[1] >= 0 && time[1] < 10) {
        cout << 0 << time[1] << ":";

    } else {
        cout << time[1] << ":";
    }
    if (time[2] >= 0 && time[2] < 10) {
        cout << 0 << time[2];

    } else {
        cout << time[2];
    }

    return 0;
}