/**
*
* Solution to homework assignment 1
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
int main() {
	int n, rev = 0;
	cin >> n;
	int digitsNumber = 0;
	//Number of digits in n
	if (n <= 0 || n >= 1e9) {
		cout << -1;
		return 0;
	}
	else {
		for (int i = n; i != 0; i /= 10) {
			rev = rev * 10 + i % 10;
			digitsNumber++;//Counts the number of digits
		}

		int compare = (digitsNumber + 1) / 2;
		int compare2 = (digitsNumber + 1) / 2;
		/*
		 Times a comparison between n and n reversed
		must be made based on the number of digits
		*/
		bool hasADigitBeenPrinted = false;
		while (compare > 0)
		{
			int a = n % 10;
			//Last digit of n
			int b = rev % 10;
			//Last digit of n reversed
			if(digitsNumber%2!=0 && compare==1){
                if(hasADigitBeenPrinted==true){
                    cout<<" ";
                }
                cout<<b;
            }
            if(a>b){
                cout<<a;
                hasADigitBeenPrinted=true;
            }
            if(b>a){
                cout<<b;
                hasADigitBeenPrinted=true;
            }
            if(compare!=1 && n/10%10!=rev/10%10){
                cout<<" ";
            }

			n /= 10;
			rev /= 10;
			compare--;
		}
	}
	return main();
}
