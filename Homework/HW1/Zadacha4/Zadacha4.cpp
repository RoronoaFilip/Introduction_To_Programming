/**
*
* Solution to homework assignment 1
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

//Sorry for the lots of comments. I wanted everything to be as understandable as possible
#include <iostream>
using namespace std;
int main() {
	//I have inputed new variables for every new center and radius,
	//so that it is easier to understand, even though it is not needed
	double x, y;
	double x1, y1, r1;
	double x2, y2, r2;
	cin >> x >> y;
	double r = (x * x) + (y * y);//Formula for the length of a circumference
	//All the values of the radiuses are ^2 since i can't use <cmath>
	if (x > 4 || y > 4 || x < -4 || y < -4) {//Outside of the square
		cout << "Outside";
		return 0;
	}
	/*
	The program ends earlier, because this condition coinsides with another one later.Same with the other return 0;-s
	*/
	if (r == 16 || x == 4 || x == -4 || y == 4 || y == -4) {//Condition the coordinate to be undefined
		cout << "Undefined";
		return 0;
	}
	if ((x<4 || x>-4) && (y<4 || y>-4) && r > 16) {
		//Condition the coordinate to be outside the circle, but inside the square
		cout << "White";
	}
	if (x == 0 && y == 0) {//The center
		cout << "Undefined";
	}
	if (x == 0 && y > 0) {//On the Y-axis
		cout << "White";
	}
	if (x == 0 && y < 0) {//On the Y-axis
		cout << "Black";
	}
	/*
	The graphic moves with 2 on the X-axis to the right, so that
	the center becomes(x1, y1) = (2, 0)(the center of the little circles on the right)
	The radius is calculated on the new center and based on its length
	it is determined where the coordinate is
	*/
	if (x > 0) {
		x1 = 2;
		y1 = 0;
		r1 = ((x - x1) * (x - x1)) + ((y - y1) * (y - y1));
		if (r1 == 1 || (y < 0 && r1 == 4)) {
			cout << "Undefined";
			return 0;
		}
		if (r1 < 1 || r1 == 0) {
			cout << "Black";
		}
		if (r1 > 1 && r1 <= 4) {
			cout << "White";
		}
		if (r1 > 4 && y < 0 && r < 16) {
			cout << "Black";
		}
		if (r1 > 4 && y > 0 && r < 16) {
			cout << "White";
		}
	}
	//By analogy with before the graphic moves to the left on the X-axis,
	//so that the center becomes (x2,y2)=(-2,0)
	if (x < 0) {
		x2 = -2;
		y2 = 0;
		r2 = ((x - x2) * (x - x2)) + ((y - y2) * (y - y2));
		if (r2 == 1 || (y > 0 && r2 == 2)) {
			cout << "Undefined";
			return 0;
		}
		if (r2 < 1 || r2 == 0) {
			cout << "White";
		}
		if (r2 > 1 && r2 <= 4) {
			cout << "Black";
		}
		if (r2 > 4 && y < 0 && r < 16) {
			cout << "Black";
		}
		if (r2 > 4 && y > 0 && r < 16) {
			cout << "White";
		}
	}
	return 0;
}
