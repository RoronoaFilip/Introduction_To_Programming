/**
 *
 * Solution to homework assignment 4
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2021/2022
 *
 * @author Filip Filchev
 * @idnumber 0MI0600041
 * @task 3
 * @compiler GCC
 *
 */
#include <iostream>
using namespace std;
bool isTrue(int begin, int end, char symbol, bool withoutPlusAndMinus) {
    int transformations[10][10];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            transformations[i][j] = -3;
        }
    }
    for (int i = 0; i < 10; ++i) {
        transformations[i][i] = -2;
    }

    // transformations[beginNumber][transformedNumber] = sticksNeededToBeAddedOrRemoved;
    transformations[0][6] = -1;
    transformations[0][8] = 1;
    transformations[0][9] = -1;
    transformations[1][7] = 1;
    transformations[2][3] = 0;
    transformations[3][9] = 1;
    transformations[3][4] = 0;
    transformations[3][2] = 0;
    transformations[3][5] = 0;
    transformations[4][3] = 0;
    transformations[5][3] = 0;
    transformations[5][3] = 0;
    transformations[5][6] = 1;
    transformations[5][9] = 0;
    transformations[6][0] = 1;
    transformations[6][5] = -1;
    transformations[6][8] = 1;
    transformations[7][1] = -1;
    transformations[8][0] = -1;
    transformations[8][6] = -1;
    transformations[8][9] = -1;
    transformations[9][0] = 1;
    transformations[9][3] = -1;
    transformations[9][5] = -1;
    transformations[9][8] = 1;
    if (symbol == '+' && !withoutPlusAndMinus) {
        return transformations[begin][end] == -1;
    }
    if (symbol == '-' && !withoutPlusAndMinus) {
        return transformations[begin][end] == 1;
    }
    if (symbol == '+' && withoutPlusAndMinus) {
        return transformations[begin][end] == 0;
    }
    if (symbol == '-' && withoutPlusAndMinus) {
        return transformations[begin][end] == 0;
    }
    return false;
}
char *returnStringPlus(int a, int b, int c, char symbol, bool withoutPlusAndMinus) {
    int neededNumber = 0;
    int previousNumber = 0;
    char *result = new char[5];
    result[0] = a + '0';
    result[1] = '+';
    result[2] = b + '0';
    result[3] = '=';
    result[4] = c + '0';
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                if (i + b == c) {
                    if (isTrue(a, i, '+', withoutPlusAndMinus)) {
                        previousNumber = a;
                        neededNumber = i;
                        result[0] = i + '0';
                        return result;
                    }
                }
                if (a + j == c) {
                    if (isTrue(b, j, '+', withoutPlusAndMinus)) {
                        previousNumber = b;
                        neededNumber = j;
                        result[2] = j + '0';
                        return result;
                    }
                }
                if (a + b == k) {
                    if (isTrue(c, k, '+', withoutPlusAndMinus)) {
                        previousNumber = c;
                        neededNumber = k;
                        result[4] = k + '0';
                        return result;
                    }
                }
            }
        }
    }

    char *elseChar = new char[2];
    elseChar[0] = 'N';
    return elseChar;
}
char *returnStringMinus(int a, int b, int c, char symbol, bool withoutPlusAndMinus) {
    int neededNumber = 0;
    int previousNumber = 0;
    char *result = new char[5];
    result[0] = a + '0';
    result[1] = '-';
    result[2] = b + '0';
    result[3] = '=';
    result[4] = c + '0';
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                if (i - b == c) {
                    if (isTrue(a, i, '-', withoutPlusAndMinus)) {
                        previousNumber = a;
                        neededNumber = i;
                        result[0] = i + '0';
                        return result;
                    }
                }
                if (a - j == c) {
                    if (isTrue(b, j, '-', withoutPlusAndMinus)) {
                        previousNumber = b;
                        neededNumber = j;
                        result[2] = j + '0';
                        return result;
                    }
                }
                if (a - b == k) {
                    if (isTrue(c, k, '-', withoutPlusAndMinus)) {
                        previousNumber = c;
                        neededNumber = k;
                        result[4] = k + '0';
                        return result;
                    }
                }
            }
        }
    }

    char *elseChar = new char[2];
    elseChar[0] = 'N';
    return elseChar;
}
int main() {
    char input[5];
    cin >> input;
    char *result = new char[5];
    //!  "a+b=c"

    int a = input[0] - '0';
    int b = input[2] - '0';
    int c = input[4] - '0';
    char symbol = input[1];

    if (symbol == '-') {
        result = returnStringPlus(a, b, c, symbol, false);
        if (result[0] == 'N') {
            result = returnStringMinus(a, b, c, symbol, true);
        }
    }
    if (symbol == '+') {
        result = returnStringMinus(a, b, c, symbol, false);
        if (result[0] == 'N') {
            result = returnStringPlus(a, b, c, symbol, true);
        }
    }
    if (result[0] == 'N') {
        cout << "No";
    } else {
        cout << result;
    }
    delete[] result;
    return 0;
}