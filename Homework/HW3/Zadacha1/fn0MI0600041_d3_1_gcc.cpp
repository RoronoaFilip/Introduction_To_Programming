/**
 *
 * Solution to homework assignment 3
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2021/2022
 *
 * @author Filip Filchev
 * @idnumber 0MI0600041
 * @task 1
 * @compiler GCC
 *
 */
#include <iostream>
using namespace std;
int countOfDifferentLetters(const char word1[], const char word2[]) {
    int count = 0;
    for (int i = 0; word1[i] != '\0'; ++i) {
        if (word1[i] != word2[i]) {
            ++count;
        }
    }
    return count;
}
int numberOfDifferentLetters(const char word1[], const char word2[]) {
    int count = 0;
    for (int i = 0; word1[i] != '\0'; ++i) {
        bool isLetterThere = false;
        for (int j = 0; word2[j] != '\0'; ++j) {
            if (word1[i] == word2[j]) {
                isLetterThere = true;
                break;
            }
        }
        if (isLetterThere == false) {
            ++count;
        }
    }
    return count;
}
int lettersCount(const char word[]) {
    int count = 0;
    for (int i = 0; word[i] != '\0'; ++i) {
        ++count;
    }
    return count;
}
bool isCorrect(const char sequence[][20], int sequenceSize) {
    bool areNumbersRight = false;
    for (int i = 0; i < sequenceSize - 1; ++i) {
        int count1 = lettersCount(sequence[i]);
        int count2 = lettersCount(sequence[i + 1]);
        int differentLetters = (count1 >= count2) ? numberOfDifferentLetters(sequence[i], sequence[i + 1]) : numberOfDifferentLetters(sequence[i + 1], sequence[i]);
        int countOfDifferences = countOfDifferentLetters(sequence[i], sequence[i + 1]);
        if (count1 == count2 && differentLetters == 0) {
            return false;
        }
        if (count1 + 1 < count2 || count2 + 1 < count1) {
            return false;
        }
        if (count1 == count2 && countOfDifferences > 1) {
            return false;
        }
        if ((count2 + 1 == count1 || count1 + 1 == count2) && differentLetters == 1) {
            areNumbersRight = true;
        }
        if (differentLetters > 1) {
            return false;
        }
        if (count1 == count2 && countOfDifferences == 1) {
            areNumbersRight = true;
        }
    }
    return (areNumbersRight) ? true : false;
}
int main() {
    int n;
    cin >> n;

    const int size = 100;
    const int wordLenght = 20;
    char words[size][wordLenght];
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }
    if (n < 2 || n > 50) {
        cout << -1;
        return 0;
    }

    cout << ((isCorrect(words, n)) ? "true" : "false");

    return 0;
}