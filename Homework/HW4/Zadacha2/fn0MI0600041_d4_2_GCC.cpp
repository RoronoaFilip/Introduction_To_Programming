/**
 *
 * Solution to homework assignment 4
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2021/2022
 *
 * @author Filip Filchev
 * @idnumber 0MI0600041
 * @task 2
 * @compiler GCC
 *
 */
#include <iostream>
using namespace std;
int strLength(const char *str) { // Length of string
    int length = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        ++length;
    }
    return length;
}
bool isAllStrInText(char *text, const char *const str1, const int startIndex) { // Check if the needed word is in the text
    int stringLength = strLength(str1);
    int index = 0;
    for (int i = startIndex; i < startIndex + stringLength; ++i) {
        if (text[i] != str1[index]) {
            return false;
        }
        ++index;
    }
    return true;
}
void replaceWord(char *&text, const char *const str1, const char *const str2, const int startIndex) { // The Replacement itself
    char copyRestOfChar[100];
    int copyRestOfCharIndex = 0;
    for (int i = startIndex + strLength(str1); text[i] != '\0'; ++i) { // Copying the rest of the text
        copyRestOfChar[copyRestOfCharIndex] = text[i];
        ++copyRestOfCharIndex;
    }

    char replaceString[1000];
    for (int i = 0; i < startIndex; ++i) {
        replaceString[i] = text[i];
    }

    int j = 0;
    for (int i = startIndex; j < strLength(str2); ++i) { // Replacing
        replaceString[i] = str2[j];
        ++j;
    }

    int end = copyRestOfCharIndex;
    copyRestOfCharIndex = 0;
    for (int i = startIndex + j; i < startIndex + j + end; ++copyRestOfCharIndex) { // Adding the rest
        replaceString[i] = copyRestOfChar[copyRestOfCharIndex];
        ++i;
    }
    delete[] text;
    for (int i = 0; replaceString[i] != '\0'; ++i) {
        text[i] = replaceString[i];
    }
}
int replace(char *text, const char *const str1, const char *const str2) {
    if (strLength(text) == 0 || strLength(str1) == 0) {
        return -3;
    }
    if (text == nullptr || str1 == nullptr || str2 == nullptr) {
        return -2;
    }
    int count = 0;
    for (int i = 0; text[i] != '\0';) {
        bool isTrue = false;
        if (text[i] == str1[0]) {
            isTrue = isAllStrInText(text, str1, i); // Check if the whole word is in the string
        }
        if (isTrue) {
            replaceWord(text, str1, str2, i); // Replace
            i = i + strLength(str2) - 1;
            // Continuing from the end of str1 in the replaced text
            ++count;
        } else {
            ++i;
        }
    }
    return count;
}
int main() {
    char text[4000];
    char str1[1000];
    char str2[1000];
    cin.getline(text, 4000);
    cin.getline(str1, 1000);
    cin.getline(str2, 1000);

    int textLength = strLength(text);
    int str1Length = strLength(str1);
    int str2Length = strLength(str2);
    // Length of String in the beginning

    int replacements = replace(text, str1, str2);
    int neededLength = (textLength - (replacements * str1Length)) + (replacements * str2Length);
    //   Calculating the Length of the String after the Replacement
    //   for printing Purpose to avoid printing unterminated String

    cout << replacements << endl;
    if (replacements != -3 && replacements != -2) {
        for (int i = 0; i < neededLength; ++i) {
            cout << text[i];
        }
    } else if (replacements == -3) {
        cout << -3;
    } else {
        cout << -2;
    }
    return 0;
}