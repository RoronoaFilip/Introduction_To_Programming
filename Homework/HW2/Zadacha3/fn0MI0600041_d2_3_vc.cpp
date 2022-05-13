/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Filip Filchev
* @idnumber 0MI0600041
* @task 3
* @compiler VC
*
*/
#include <iostream>
using namespace std;
int main() {
	int begin, result;
	int counter = 0;
	cin >> begin >> result;

	if (begin == 0 && result > 0) {
		cout << -1;
		return 0;
	}

	if (begin < 0 && result <= 0) {
		if (begin < result) {
			cout << -1;
			return 0;
		}
	}

	if (begin > result) {
		while (begin != result) {
			--begin;
			++counter;
		}
		cout << counter;
		return 0;
	}

	else while (result != begin) {
		if (result % 2 != 0) {
			++result;
			++counter;
		}
		result /= 2;
		++counter;
		if (result < begin) {
			while (result != begin) {
				++result;
				++counter;
			}
		}

	}
	cout << counter;

	return 0;
}
