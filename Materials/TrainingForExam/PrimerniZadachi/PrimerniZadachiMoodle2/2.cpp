#include <iostream>
using namespace std;
//Да се напише функция на С++, със сигнатура void Revert(char []), която преобразува
//подадения като параметър символен низ, като замества всички малки букви от латинската азбука с главни и обратно.
//Да не се използва вградената библиотека string.

void Revert(char word[]) {
    const int difference = 'a' - 'A';
    for (int i = 0; word[i] != '\0'; ++i) {
        if (word[i] >= 65 && word[i] <= 90) {
            word[i] += difference;
        } else if (word[i] >= 97 && word[i] <= 122) {
            word[i] -= difference;
        }
    }
}
int main() {
    const int SIZE = 100;
    char word[SIZE];
    cin >> word;
    Revert(word);
    cout << word;
    return 0;
}