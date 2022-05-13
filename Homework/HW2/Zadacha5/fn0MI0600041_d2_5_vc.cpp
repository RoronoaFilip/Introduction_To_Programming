/**
 *
 * Solution to homework assignment 2
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

void Date(int date) {
	if (date < 10) {
		cout << 0 << date << ".";
	}
	else
		cout << date << ".";
}

void Month(int month) {
	if (month < 10) {
		cout << 0 << month << ".";
	}
	else
		cout << month << ".";
}

void Year(int year) {
	if (year < 10) {
		cout << 0 << year << " ";
	}
	else
		cout << year << " ";
}

void Hours(int hours) {
	if (hours < 10) {
		cout << 0 << hours << ":";
	}
	else
		cout << hours << ":";
}

void Minutes(int minutes) {
	if (minutes < 10) {
		cout << 0 << minutes << ":";
	}
	else
		cout << minutes << ":";
}

void Seconds(int seconds) {
	if (seconds < 10) {
		cout << 0 << seconds;
	}
	else
		cout << seconds;
}

int main() {
	long long int n;
	cin >> n;
	if (n < 0) {
		cout << -1;
		return 0;
	}
	int seconds = 0, minutes = -1, hours = 0, date = 1, month = 1, year = 1970;
	for (long long int i = n; i >= 0; i = i - 60) {

		++minutes;
		if (minutes == 60) {
			++hours;
			minutes = 0;
		}
		if (hours == 24) {
			hours = 0;
			++date;
		}

		if (month <= 7) {

			if (month % 2 != 0) {
				if (date == 32) {
					date = 1;
					++month;
				}
			}
			if (month % 2 == 0) {
				if (date == 31) {
					date = 1;
					++month;
				}
			}
			if ((year % 4 == 0 && year / 4 % 100 != 0) || (year % 400 == 0)) {
				if (month == 2) {
					if (date == 30) {
						date = 1;
						++month;
					}
				}
			}
			if (!((year % 4 == 0 && year / 4 % 100 != 0) || (year % 400 == 0))) {
				if (month == 2) {
					if (date == 29) {
						date = 1;
						++month;
					}
				}
			}
		}

		if (month >= 8) {

			if (month % 2 == 0 && month != 12) {
				if (date == 32) {
					date = 1;
					++month;
				}
			}
			if (month % 2 != 0) {
				if (date == 31) {
					date = 1;
					++month;
				}
			}
			if (month == 12) {
				if (date == 32) {
					date = 1;
					month = 1;
					++year;
				}
			}
		}

		n -= 60;
	}

	seconds = 60 + n;

	Date(date);
	Month(month);
	Year(year);
	Hours(hours);
	Minutes(minutes);
	Seconds(seconds);
	return 0;
}
