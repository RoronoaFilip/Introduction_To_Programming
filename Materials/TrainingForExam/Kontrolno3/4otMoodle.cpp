#include <iostream>
using namespace std;

void returnNum(int &n) {
    int sum = 0;
    int count = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
        ++count;
    }
    n = sum / count;
}

int main() {
    int num1 = 7;
    int num2 = 28;
    int num;
    cin >> num;
    returnNum(num1);
    returnNum(num2);
    returnNum(num);
    cout << num1 << " " << num2 << " " << num;

    return 0;
}