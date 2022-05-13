/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Filip Filchev
* @idnumber 0MI0600041
* @task 2
* @compiler VC
*
*/
#include <iostream>
using namespace std;
void reverseNumber(int& n) {
	int reversedNumber = 0;
	while (n != 0) {
		reversedNumber = reversedNumber * 10 + n % 10;
		n /= 10;
	}
	n = reversedNumber;
}
int main() {
	int n;
	cin >> n;
	int n1 = n;
	int n2 = n;

	if ((n < 1) || (n > 1e9)) {
		cout << -1;
		return 0;
	}
	if (n <= 106) {
		cout << 101;
		return 0;
	}

	int higherPalindrome = 0;
	while (true) {
		int higherNumber = n1;
		reverseNumber(n1);
		if (higherNumber != n1) {
			higherNumber++;
		}
		else {
			higherPalindrome = higherNumber;
			break;
		}
		n1 = higherNumber;
	}

	int lowerPalindrome = 0;
	while (true) {
		int lowerNumber = n2;
		reverseNumber(n2);
		if (lowerNumber != n2) {
			lowerNumber--;
		}
		else {
			lowerPalindrome = lowerNumber;
			break;
		}
		n2 = lowerNumber;
	}

	int diffWithLower = n - lowerPalindrome;
	int diffWithHigher = higherPalindrome - n;

	if (diffWithLower <= diffWithHigher) {
		cout << lowerPalindrome;
	}
	else cout << higherPalindrome;

	return 0;
}
