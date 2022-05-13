#include <iostream>
using namespace std;
//Да се напише функция на С++, със сигнатура bool CheckDate(char[]), която да проверява дали
// входния параметър е коректна дата във формат DD.MM. Да не се използва вградената библиотека string.

int charLength(char word[]) {
    int size = 0;
    for (int i = 0; word[i] != '\0'; ++i) {
        ++size;
    }
    return size;
}

bool CheckDate(char word[]) {
    int size = charLength(word);
    if (size != 5) {
        return false;
    }
    if (word[2] != '.') {
        return false;
    }
    if (word[0] < '0' || word[0] > '9') {
        return false;
    }
    if (word[1] < '0' || word[1] > '9') {
        return false;
    }
    if (word[3] < '0' || word[3] > '9') {
        return false;
    }
    if (word[4] < '0' || word[5] > '9') {
        return false;
    }
    int month = 0;
    month = (word[3] - '0') * 10 + (word[4] - '0');
    int date = 0;
    date = (word[0] - '0') * 10 + (word[1] - '0');
    if (month < 1 || month > 12) {
        return false;
    }
    if (date < 1 || date > 31) {
        return false;
    }
    if (month == 2 && date > 29) {
        return false;
    }
    if (month <= 7 && month % 2 == 0 && date > 30) {
        return false;
    }
    if (month <= 7 && month % 2 == 1 && date > 31) {
        return false;
    }
    if (month > 7 && month % 2 == 1 && date > 31) {
        return false;
    }
    if (month > 7 && month % 2 == 1 && date > 30) {
        return false;
    }
    return true;
}
int main() {
    const int SIZE = 100;
    char word[SIZE];
    cin >> word;

    cout << CheckDate(word);
    return 0;
}