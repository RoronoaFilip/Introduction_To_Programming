/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Filip Filchev
* @idnumber 0MI0600041
* @task 5
* @compiler VC
*
*/
#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n < 0) {
		cout << -1 << endl;
		return 0;
	}
	int rev = 0;
	int num = 0;
	int a;
	for (int i = n; i != 0; i = i / 10) {
		rev = rev * 10 + i % 10;
	}
	//First the number is inverted, otherwise it will be inverted later
	for (int i = rev; i != 0; i = i / 10) {
		a = i % 10;
		if (a % 2 != 0) {
			num = num * 10 + a;
		}
	}
	cout << num;
	return 0;
}
