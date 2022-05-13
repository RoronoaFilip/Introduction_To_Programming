/**
*
* Solution to homework assignment 1
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
	int numberSites;
	int salary;
	cin >> numberSites;
	if (numberSites < 1 || numberSites>10) {
		cout << -1;
		return 0;
	}
	cin >> salary;
	if (salary < 700 || salary>1500) {
		cout << -1;
		return 0;
	}
	char x;   //Char that plays the role of the letter
	int sizex = 1;   //Number of chars
	while (sizex <= numberSites)
	{
		cin >> x;
		if (x == 'F' || x == 'I' || x == 'R' || x == 'd' || x == 'f' || x == 'i' || x == 'r' || x == 'D') {
			if (x == 'F' || x == 'f') {
				salary = salary - 150;
			}
			else if (x == 'I' || x == 'i') {
				salary = salary - 100;
			}
			else if (x == 'R' || x == 'r') {
				salary = salary - 50;
			}
			else if (x == 'd' || x == 'D') {
				salary = salary - 0;
			}
			if (salary <= 0) {
				cout << "You have lost your salary";
				return 0;
			}   //The program terminates, if the salary reaches 0 or below 0
		}
		else {
			cout << -1;
			return 0;
		}  //The program terminates, if the chars are different from the needed ones
		sizex = sizex + 1;
	}
	cout << salary;
	return 0;
}
