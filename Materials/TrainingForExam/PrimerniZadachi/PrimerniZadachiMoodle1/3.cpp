#include <iostream>
using namespace std;
//Да се напише функция на С++, която отпечатва в конзолата запълнен правоъгълник с размерност NxM,
// където N, M и символът за отпечатване на правоъгълника се предават като параметри на функцията.
// Правоъгълникът да е центриран (приема се, че конзолата има 25 реда и 80 символа на ред).

void printIt(int n, int m, char symbol) {
    for (int i = 0; i < (25 - n) / 2; i++) {
        cout << endl;
    }
    int line = 0;
    while (line != n) {
        for (int i = 0; i < (80 - m) / 2; i++) {
            cout << ' ';
        }
        for (int i = 0; i < m; i++) {
            cout << symbol;
        }
        ++line;
        cout << endl;
    }
    for (int i = 0; i < (25 - n) / 2; i++) {
        cout << endl;
    }
}

int main() {
    int n, m;
    char symbol;
    cin >> n >> m >> symbol;
    printIt(n, m, symbol);
    return 0;
}