/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Filip Filchev
* @idnumber 0MI0600041
* @task 1
* @compiler VC
*
*/
#include <iostream>
using namespace std;

bool hasAlternatingBits(unsigned n) {
	bool areBitsDifferent = false;
	if (n == 0) {
		return true;
	}

	while (n != 0) {
		int lastDigit = n % 2;
		n /= 2;
		int secondToLastDigit = n % 2;
		if (lastDigit != secondToLastDigit) {
			areBitsDifferent = true;
		}
		else {
			return false;
		}
	}
	return areBitsDifferent;
}

int main() {
	int n;
	cin >> n;

	if (n < 0) {
		cout << -1;
		return 0;
	}

	if (hasAlternatingBits(n) == true) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	return 0;
}
