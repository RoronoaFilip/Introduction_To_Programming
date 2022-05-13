#include <iostream>
using namespace std;
bool CheckDate(char year[]) { // 2016
    int count = 0;
    for (int i = 0; year[i] != ' '; ++i) {
        ++count;
    }
    if (count != 7) { //!!!!!!!!!!!!
        return false;
    }
    int yearInt = 0;
    for (int i = 0; year[i] != ' '; ++i) {
        yearInt = yearInt * 10 + (year[i] - 48);
    }
    if ((yearInt % 4 == 0 && yearInt / 4 % 100 != 0) || yearInt % 400 == 0) {
        return true;
    } else {
        return false;
    }
}
int main() {
    char year[100];
    cin.getline(year, 100);
    cout << CheckDate(year);
    return 0;
}