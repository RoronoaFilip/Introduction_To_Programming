/**
 *
 * Solution to homework assignment 3
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2021/2022
 *
 * @author Filip Filchev
 * @idnumber 0MI0600041
 * @task 4
 * @compiler GCC
 *
 */
#include <iostream>
using namespace std;

int findIndexOfTheSameLetter(const char str[], int index, int begin, int letter) {
    int neededIndex = 0;
    for (int i = 0; i < index; ++i) {
        if (letter == str[i]) {
            neededIndex = i;
        }
    }
    return neededIndex;
}
bool isTheNextLetterTheSame(const char str[], int index, int begin, int letter) {
    for (int i = begin; i < index; ++i) {
        if (letter == str[i]) {
            return true;
        }
    }
    return false;
}
int longestSubstrWithUniqueSymbolsLength(const char str[]) {
    const int SIZE = 101;
    int differentCounts[SIZE] = {};
    int differentCountsIndex = 0;

    char substr[SIZE] = {};
    int substrIndex = 0;

    int begin = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (i == 0) {
            substr[substrIndex] = str[i];
            ++substrIndex;
        } else if (i != 0 && isTheNextLetterTheSame(str, i, begin, str[i]) == false) {
            substr[substrIndex] = str[i];
            ++substrIndex;
        } else if (i != 0 && isTheNextLetterTheSame(str, i, begin, str[i]) == true) {
            int indexOfTheSameLetter = findIndexOfTheSameLetter(str, i, begin, str[i]);
            int substreamLetterCount = 0;
            for (int j = 0; substr[j] != '\0'; ++j) {
                ++substreamLetterCount;
            }
            differentCounts[differentCountsIndex] = substreamLetterCount;
            ++differentCountsIndex;
            begin = i;
            i = indexOfTheSameLetter;
            substrIndex = 0;
        }
        if (str[i + 1] == '\0') {
            int substreamLetterCount = 0;
            for (int j = 0; substr[j] != '\0'; ++j) {
                ++substreamLetterCount;
            }
            differentCounts[differentCountsIndex] = substreamLetterCount;
        }
    }

    int max = differentCounts[0];
    for (int i = 1; differentCounts[i] != '\0'; ++i) {
        if (max < differentCounts[i]) {
            max = differentCounts[i];
        }
    }
    return max;
}
int main() {
    const int SIZE = 101;
    char word[SIZE] = {};
    cin >> word;
    for (int i = 0; word[i] != '\0'; ++i) {
        if (word[i] < 97 || word[i] > 122) {
            cout << -1;
            return 0;
        }
    }
    cout << longestSubstrWithUniqueSymbolsLength(word);
    return 0;
}