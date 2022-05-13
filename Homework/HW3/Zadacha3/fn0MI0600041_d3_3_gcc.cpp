/**
 *
 * Solution to homework assignment 3
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2021/2022
 *
 * @author Filip Filchev
 * @idnumber 0MI0600041
 * @task 3
 * @compiler GCC
 *
 */
#include <iostream>
using namespace std;
void printPasswords(int a, int b, int numberOfPasswords) {
    char A = 35;
    char B = 64;
    int x = 1;
    int y = 1;
    int passwordsPrinted = 0;
    while (true) {
        cout << A << B << x << y << B << A << '|';
        ++passwordsPrinted;
        ++A;
        ++B;
        ++y;
        if (A > 55) {
            A = 35;
        }
        if (B > 96) {
            B = 64;
        }
        if ((x == a && y == b + 1) || passwordsPrinted == numberOfPasswords) {
            break;
        }
        if (y > b) {
            ++x;
            y = 1;
        }
    }
}
int main() {
    int a, b, numberOfPasswords;
    cin >> a >> b >> numberOfPasswords;
    if ((a < 1 || a > 1000) || (b < 1 || b > 1000) || (numberOfPasswords < 1 || numberOfPasswords > 1000000)) {
        cout << -1;
        return 0;
    }
    printPasswords(a, b, numberOfPasswords);

    return 0;
}