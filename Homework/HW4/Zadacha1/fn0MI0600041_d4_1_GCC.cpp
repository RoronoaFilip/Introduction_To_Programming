/**
 *
 * Solution to homework assignment 4
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

int numberOfLetters(char word[]) {
    int count = 0;
    for (int i = 0; word[i] != '\0'; ++i) {
        ++count;
    }
    return count;
}

int numberOfPermutations(char word[]) {
    int count = 1;
    for (int i = 0; word[i] != '\0'; ++i) {
        if ((word[i] >= 97 && word[i] <= 122)) {
            count *= 2;
        }
    }
    return count;
}

char *upperCase(char *word, int b) {
    char *word2 = new char[numberOfLetters(word)];
    for (int i = 0; i < numberOfLetters(word); ++i) {
        word2[i] = word[i];
    }
    word2[b] -= 32;
    return word2;
}
int findNextLetter(char word[], int b) {
    for (int i = b + 1; word[i] != '\0'; ++i) {
        if (word[i] >= 97 && word[i] <= 122) {
            return i;
        }
    }
    return -1;
}
char **returningPermutations(char **word, int numberOfElements, int j) {
    const int SIZE = numberOfPermutations(word[0]);
    char **finalWord = new char *[SIZE]; // The Number of Pointers is always the Number of Permutations
    for (int i = 0; i < SIZE; ++i) {
        finalWord[i] = new char[numberOfLetters(word[0])];
    }
    int index = numberOfElements;
    int finalWordIndex = 0;

    for (int i = 0; i < index; ++i) {
        finalWord[finalWordIndex] = word[i];
        finalWord[finalWordIndex + 1] = upperCase(word[i], j);
        finalWordIndex += 2;
    }

    numberOfElements = finalWordIndex;

    if (numberOfElements < numberOfPermutations(word[0])) {
        finalWord = returningPermutations(finalWord, numberOfElements, j = findNextLetter(word[0], j));
    }
    return finalWord;
}

char *makeLettersLowerCase(char *word) {
    int diff = 'a' - 'A';
    for (int i = 0; word[i] != '\0'; ++i) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            word[i] += diff;
        }
    }
    return word;
}

char **letterCasePermutation(char str[]) {
    const int SIZE = numberOfPermutations(str);
    char **finalWord = new char *[SIZE]; // The Number of Pointers is always the Number of Permutations
    for (int i = 0; i < SIZE; ++i) {
        finalWord[i] = new char[numberOfLetters(str)];
    }
    finalWord[0] = makeLettersLowerCase(str); // Letters become all lower Case
    finalWord = returningPermutations(finalWord, 1, 0);
    return finalWord;
}

int main() {
    char word[50];
    cin >> word;
    char **result = letterCasePermutation(word);
    for (int i = 0; i < numberOfPermutations(word); ++i) {
        if (i != 0) {
            cout << " ";
        }
        for (int j = 0; j < numberOfLetters(word); ++j) {
            cout << result[i][j];
        }
    }

    return 0;
}
