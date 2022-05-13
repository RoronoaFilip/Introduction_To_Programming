#include <iostream>
#include <string>
using namespace std;
bool isTrue(char *word, int begin, int end) {
    if (((word[begin - 1] >= 'A' && word[begin - 1] <= 'Z')) && ((word[begin + 1] >= 'a' && word[begin + 1] <= 'z'))) {
        return false;
    }
    if (((word[begin - 1] >= 'a' && word[begin - 1] <= 'z')) && ((word[begin + 1] >= 'A' && word[begin + 1] <= 'Z'))) {
        return false;
    }
    if (end == begin) {
        return true;
    } else {
        return isTrue(word, begin + 1, end);
    }
}
bool checkstr(char *word) {
    if (word == nullptr) {
        return false;
    }
    int index = 0;
    for (int i = 0; word[i] != '\0'; ++i) {
        ++index;
    }
    int begin = 1;
    int end = index - 2;
    return isTrue(word, begin, end);
}
int main() {
    int a;
    char word[60] = "aZaAaCfEaA";
    cout << checkstr(word);
    return 0;
}