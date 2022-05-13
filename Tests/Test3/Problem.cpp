#include <iostream>
using namespace std;

// Function that reverts a Number

int revertedNumber(int n) {
    int reverted = 0;

    while (n != 0) {
        reverted = (reverted * 10) + (n % 10);
        n /= 10;
    }
    return reverted;
}
int main() {

    int n;
    cin >> n;
    int m, r;
    cin >> m >> r;

    cout << revertedNumber(n);
    cout << endl;
    cout << revertedNumber(m);
    cout << endl;
    cout << revertedNumber(r);
    return 0;
}