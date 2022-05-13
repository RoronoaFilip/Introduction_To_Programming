#include <iostream>
using namespace std;
//Да се напише функция на C++, със сигнатураbool doExist(char *symbols, char *word), която проверява дали думата word,
// се среща в символният низ symbols.Да не се използва вградената библиотека string.

int strSize(char *str) {
    int size = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        ++size;
    }
    return size;
}
bool isItThere(char *symbols, char *word, int index) {
    for (int i = 0; word[i] != '\0'; ++i) {
        if (symbols[index] != word[i]) {
            return false;
        }
        ++index;
    }
    return true;
}
bool doExist(char *symbols, char *word) {
    int symbolsSize = strSize(symbols);
    int wordSize = strSize(word);
    if (wordSize > symbolsSize) {
        return false;
    }
    wordSize--;
    symbolsSize--;
    bool isThere = false;
    for (int i = 0; i <= symbolsSize - wordSize; ++i) {
        if (symbols[i] == word[0]) {
            isThere = isItThere(symbols, word, i);
        }
        if (isThere) {
            return true;
        }
    }
    return false;
}
int main() {
    char symbols[50];
    char word[50];
    cin >> symbols >> word;
    cout << doExist(symbols, word);
    return 0;
}