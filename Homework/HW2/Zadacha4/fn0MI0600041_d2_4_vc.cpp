/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Filip Filchev
* @idnumber 0MI0600041
* @task 4
* @compiler VC
*
*/
#include <iostream>
using namespace std;

int digitcounter(int number) {
	int numberOfDigits = 0;
	while (number != 0) {
		numberOfDigits++;
		number /= 10;
	}
	return numberOfDigits;
}

int swapRemoveAddDigit(int begin[], int result[], int indexBegin, int indexResult, int& counter) {
	if (indexBegin <= indexResult) {
		for (int i = 0; i <= indexBegin; ++i) {
			if (begin[i] != result[i] && i == indexBegin) {//  The number of operations when a gets 
				counter++;                                //   removed and another one gets added is 2
				counter++;
			}
			if (begin[i] != result[i] && i < indexBegin) {//    The number of operations when a digit goes at the end, gets removed,
				counter++;                               //     another one gets added and goes back on its place, is 4
				counter++;
				counter++;
				counter++;
			}
		}
	}
	if (indexBegin > indexResult) {
		for (int i = 0; i <= indexResult; ++i) {
			if (begin[i] != result[i] && i == indexResult) {
				counter++;
				counter++;
			}
			if (begin[i] != result[i] && i < indexResult) {
				counter++;
				counter++;
				counter++;
				counter++;
			}
		}
	}
	return counter;
}

int makingNumberOfDigitsEqual(int digitsBegin, int digitsResult, int& counter) {
	if (digitsBegin > digitsResult) {
		while (digitsBegin != digitsResult) {
			digitsBegin--;
			counter++;
		}

	}
	else if (digitsResult > digitsBegin) {
		while (digitsBegin != digitsResult) {
			digitsBegin++;
			counter++;
		}
	}
	return counter;
}

int main() {
	int n, m;
	cin >> n >> m;

	int digitsBegin = digitcounter(n);
	int indexBegin = digitsBegin - 1;

	int digitsResult = digitcounter(m);
	int indexResult = digitsResult - 1;

	const int size = 50;
	int begin[size] = {};
	for (int i = indexBegin; i >= 0; --i) {
		begin[i] = n % 10;
		n /= 10;
	}

	int result[size] = {};
	for (int i = indexResult; i >= 0; --i) {
		result[i] = m % 10;
		m /= 10;
	}

	int counter = 0;
	for (int i = 0; i <= indexResult; ++i) {
		for (int j = 0; j <= indexBegin; ++j) {
			if (begin[j] != result[j] && begin[j] == result[i] && begin[i] != -1) {
				int temp = begin[i];
				begin[i] = begin[j];
				begin[j] = temp;
				counter++;
				break;
			}
		}
	}

	swapRemoveAddDigit(begin, result, indexBegin, indexResult, counter);
	makingNumberOfDigitsEqual(digitsBegin, digitsResult, counter);

	if ((digitsBegin + digitsResult) < counter) {
		cout << digitsBegin + digitsResult;
	}
	else cout << counter;
	return 0;
}
