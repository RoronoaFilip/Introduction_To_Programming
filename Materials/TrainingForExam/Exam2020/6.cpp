#include <iostream>
using namespace std;
char *GetWord(char word[]) {
    char finalChar[100] = {};
    int finalCharIndex = 0;
    for (int i = 0; word[i] != '\0'; ++i) {
        if (word[i] == ' ' && word[i - 1] == ' ') {
            continue;
        }
        finalChar[finalCharIndex] = word[i];
        ++finalCharIndex;
    }
    int count = 0;
    for (int i = 0; finalChar[i] != '\0'; ++i) {
        if (finalChar[i] == ' ') {
            ++count;
        }
    }
    if (finalChar[0] == ' ') {
        --count;
    }
    int count2 = 0;
    for (int i = 0; finalChar[i] != '\0'; ++i) {
        if (finalChar[0] == 'a') {
            ++count2;
        }
        if (finalChar[i] == ' ' && finalChar[i + 1] == 'a') {
            ++count2;
        }
    }

    char *result;
    result[0] = count2 + '0';
    result[1] = count + '0';

    return result;
}
int main() {
    char word[200] = " It took      about      an hour to                  answer all the questions.              ";
    char *result = GetWord(word);
    cout << result[0] << result[1];
    return 0;
}