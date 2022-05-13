#include <iostream>
using namespace std;
double avarage(long a, long b) { return (a + b) / 2.0; }
int findElement(long arr[], int l) {
    int max = 1;
    for (int i = 1; i < l - 1; ++i) {
        if (arr[i] > avarage(arr[i - 1], arr[i + 1])) {
            max = i;
        }
    }
    if (l < 3) {
        return -1;
    }
    return max;
}
int main() {
    long int a[50] = {2, 3, 17, 8, 60, 5};
    int l = 6;
    int x = findElement(a, l);
    cout << x;
    return 0;
}