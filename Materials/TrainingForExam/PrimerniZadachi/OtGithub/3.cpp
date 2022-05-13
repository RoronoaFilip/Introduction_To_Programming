#include <Windows.h>
#include <iostream>
using namespace std;
void rectangle(char symbol, int n, int m) {

    for (int i = 1; i <= (25 - n) / 2; ++i) {
        cout << endl;
    }
    int line = 1;
    while (line <= n) {
        for (int i = 1; i <= (80 - m) / 2; ++i) {
            cout << ' ';
        }
        for (int i = 1; i <= m; ++i) {
            cout << symbol;
        }
        cout << endl;
        ++line;
    }
    for (int i = 1; i <= (25 - n) / 2; ++i) {
        cout << endl;
    }
}
int main() {
    int a;
    int n, m;
    cin >> n >> m;
    char symbol;
    cin >> symbol;
    rectangle(symbol, n, m);
    Sleep(100000);
    return 0;
}