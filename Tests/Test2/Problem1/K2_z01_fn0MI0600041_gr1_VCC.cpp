//Filip Filchev 0MI0600041
#include <iostream>
using namespace std;
void reverseNumber(int n) {
	int reversedNumber = 0;
	bool hasADigitBeenPrinted = false;
	while (n != 0) {
		if (n % 10 == 0 && hasADigitBeenPrinted == false) {
			cout << 0;
		}
		else {
			reversedNumber = reversedNumber * 10 + n % 10;
			hasADigitBeenPrinted = true;
		}
		n /= 10;
	}
	cout << reversedNumber;
}
int main() {
	int n;
	cin >> n;
	reverseNumber(n);

	return 0;
}
