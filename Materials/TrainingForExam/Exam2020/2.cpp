#include <iostream>
using namespace std;
char *revandreplace(char *word) {
    if (word == nullptr) { //!!!!!!!!!!!!!!!!
        return false;
    }
    int count = 0;
    for (int i = 0; word[i] != '\0'; ++i) {
        ++count;
    }
    int index = count - 1;
    for (int i = 0; i <= index / 2; ++i) {
        char swap = word[i];
        word[i] = word[count - 1];
        word[count - 1] = swap;
        --count;
    }
    for (int i = 0; word[i] != '\0'; ++i) {
        if (word[i] == 'e') {
            word[i] = '!';
        }
        if (word[i] == 'y') {
            word[i] = '*';
        }
    }
    char *result = word;
    return word;
}
int main() {
    char word[100] = "I left you alone";
    char *copy = revandreplace(word);
    cout << copy;
    return 0;
}