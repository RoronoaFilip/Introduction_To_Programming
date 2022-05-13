#include <iostream>
using namespace std;
int numberSize(long N) {
    int count = 0;
    while (N) {
        ++count;
        N /= 10;
    }
    return count;
}
int AnalyzeNum(long N) {
    int numSize = numberSize(N);
    int numArr[50] = {};
    for (int i = numSize - 1; i >= 0; --i) {
        numArr[i] = N % 10;
        N /= 10;
    }
    int index = numSize - 1;
    int neededNum = 0;
    while (numSize > 0) {
        for (int i = 0; i <= index; ++i) {
            int count = 0;
            int count2 = 0;
            for (int j = 0; j <= index; ++j) {
                if (i == j) {
                    continue;
                }
                if (numArr[i] <= numArr[j]) {
                    ++count;
                }
                if (numArr[i] > numArr[j]) {
                    ++count2;
                }
            }
            if (count == count2) {
                neededNum = numArr[i];
            }
        }
        --numSize;
    }
    if (neededNum == 0) {
        return -1;
    }
    return neededNum;
}

int main() {
    long N;
    cin >> N;
    cout << AnalyzeNum(N);
    return 0;
}