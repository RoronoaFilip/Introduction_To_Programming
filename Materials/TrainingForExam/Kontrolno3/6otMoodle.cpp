#include <iostream>
using namespace std;

int returnSumOfDigits(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n1 = 5;
    int n2 = 67;
    int n;
    cin >> n;
    cout << returnSumOfDigits(n1) << " ";
    cout << returnSumOfDigits(n2) << " ";
    cout << returnSumOfDigits(n);
    return 0;
}