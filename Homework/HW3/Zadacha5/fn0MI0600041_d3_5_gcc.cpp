/**
 *
 * Solution to homework assignment 3
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2021/2022
 *
 * @author Filip Filchev
 * @idnumber 0MI0600041
 * @task 5
 * @compiler GCC
 *
 */
#include <iostream>
using namespace std;

bool isInputCorrect(char word[]) {
    bool isStringCorrect = true;
    for (int i = 0; word[i] != '\0'; ++i) {
        if (!((word[i] >= 65 && word[i] <= 90) || (word[i] >= 97 && word[i] <= 122))) {
            return false;
        }
    }
    return true;
}
bool areLowerUpperCaseLetterTheSame(char X[]) {
    const int SIZE = 256;
    char s[SIZE] = {};
    char S[SIZE] = {};

    int upperCaseIndex = 0;
    for (int i = 0; X[i] != '\0'; ++i) {
        if (X[i] >= 65 && X[i] <= 90) {
            S[upperCaseIndex] = X[i];
            ++upperCaseIndex;
        }
    }

    int lowerCaseIndex = 0;
    for (int i = 0; X[i] != '\0'; ++i) {
        if (X[i] >= 97 && X[i] <= 122) {
            s[lowerCaseIndex] = X[i];
            ++lowerCaseIndex;
        }
    }
    if (upperCaseIndex != lowerCaseIndex) {
        return false;
    }
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] != S[i] + 32) {
            return false;
        }
    }
    return true;
}
int main() {
    const int SIZE = 256;
    char X[SIZE];
    cin >> X;
	
    if (!isInputCorrect(X)) {
        cout << -1;
        return 0;
    }
    cout << ((areLowerUpperCaseLetterTheSame(X)) ? "Yes" : "No");
    return 0;
}