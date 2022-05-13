#include <iostream>
using namespace std;
//Да се напише функция на C++, със сигнатура int DigitPos(long num, int k), която връща като резултат
// k - тата цифра на числото num или - 1, ако такава не съществува.
//Брои се от ляво на дясно и се започва от 1.
int numLength(long num) {
    int length = 0;
    while (num != 0) {
        ++length;
        num /= 10;
    }
    return length;
}
int DigitPos(long num, int k) {
    int neededIndex = k - 1;
    int size = numLength(num);
    if (k > size || k < 1) {
        return -1;
    }
    int diff = size - k;
    for (int i = 1; i <= diff; ++i) {
        num /= 10;
    }
    return num % 10;
}
int main() {
    long num;
    int k;
    cin >> num >> k;
    cout << DigitPos(num, k);
    return 0;
}