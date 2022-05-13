/**
*
* Solution to homework assignment 1
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
int main() {

	int n;
	cin >> n;
	int x = 1;
	int y = n;
	if (n >= 1 && n <= 9) {
		while (x <= n) {
			for (int i = x; i <= n; i++) {
				cout << i;
			}
			cout << endl;
			if (x == n) {
				break;//The loop stops when the goal is reached, so that further whitespaces aren't printed
			}
			for (int i = 0; i < x; i++) {
				cout << " ";
				//On every new line are printed so many whitespaces as much letters are missing
			}
			x++;//x ups in value so that the next loop starts printing from 2
		}

		while (y > 1) {
			for (int i = 1; i < n; i++) {
				cout << " ";
				//Every new line the same amount of whitespaces are printed
			}
			for (int i = n; i >= y - 1; i--) {
				cout << i;
				//The numbers are printed while they are bigger than y-1
			}
			cout << endl;
			y = y - 1;//The value of y decreases
		}
	}
	else {
		cout << -1;
		return 0;
	}
	return 0;
}
