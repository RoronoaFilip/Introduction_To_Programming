#pragma once

#ifndef SOLUTIONS_H
#define SOLUTIONS_H

double fabs(double x) { return (x >= 0) ? x : -x; }

int numberLenght(int num) {
    int lenght = 0;
    while (num != 0) {
        ++lenght;
        num /= 10;
    }
    return lenght;
}
int DigitPos(long num, int k) {
    int numLen = numberLenght(num);
    if (numLen < k || k < 0) {
        return -1;
    }
    for (int i = numLen; i != k; --i) {
        num /= 10;
    }
    return (num % 10 >= 0) ? num % 10 : -(num % 10);
}
void Revert(char word[]) {
    int diff = 'a' - 'A';
    for (int i = 0; word[i] != '\0'; ++i) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            word[i] += diff;
            continue;
        }
        if (word[i] >= 'a' && word[i] <= 'z') {
            word[i] -= diff;
            continue;
        }
    }
    return;
}

int *mergeArrays(int arr1[], int arr2[], int m) {
    int *merged = new int[m];
    if (arr1 == nullptr || arr2 == nullptr) {
        for (int i = 0; i < m; ++i) {
            merged[i] = -1;
        }
        return merged;
    }
    int index1 = 0;
    int index2 = m - 1;
    for (int i = 0; i < m; ++i) {
        merged[i] = arr1[index1] + arr2[index2];
        ++index1;
        --index2;
    }
    return merged;
}
int numberLen(int num) {
    int count = 1;
    while (num != 0) {
        count *= 10;
        num /= 10;
    }
    count /= 10;
    return count;
}

double sqrt_a(double a, double eps) {
    double x = a;
    double x1 = (a + 1) / 2;
    while (fabs(x1 - x) >= eps) {
        x = x1;
        x1 = (x1 + a / x1) / 2;
    }

    return x1;
}
double myCos(double x) {
    const double eps = 1e-5;
    double temp = 1;
    double ch = 1;
    double zn = 1;
    double sum = 1;
    double fact = 0;
    while (fabs(temp) >= eps) {
        ch *= -x * x;
        zn *= (fact + 1) * (fact + 2);
        fact += 2;
        temp = ch / zn;
        sum += temp;
    }

    return sum;
}
double myExp(double x) {
    const double eps = 1e-5;
    double sum = 1;
    double ch = 1;
    double zn = 1;
    double temp = 1;
    double fact = 0;
    while (fabs(temp) >= eps) {
        ch *= x;
        zn *= (fact + 1);
        fact += 1;
        temp = ch / zn;
        sum += temp;
    }

    return sum;
}
int lenght(long n) {
    int count = 0;
    while (n != 0) {
        ++count;
        n /= 10;
    }
    return count;
}
int AnalyzeNum(long N) {
    int numlen = lenght(N);
    const int SIZE = 1000;
    int arr[SIZE] = {};
    long numCopy = N;
    for (int i = numlen - 1; i >= 0; --i) {
        arr[i] = numCopy % 10;
        numCopy /= 10;
    }

    for (int i = 0; i < numlen - 1; ++i) {
        int countLower = 0;
        int countHigher = 0;
        for (int j = i + 1; j < numlen; ++j) {
            if (arr[j] > arr[i]) {
                ++countHigher;
            }
            if (arr[j] < arr[i]) {
                ++countLower;
            }
        }
        if (countHigher == countLower) {
            return arr[i];
        }
    }

    return -1;
}

//==========================

int largestSeq(int nums[], long N) {
    const int SIZE = 50;
    int sums[SIZE] = {};
    int sumsIndex = 0;
    for (int i = 0; i < N;) {
        int sum = 0;
        if (i == N) {
            break;
        }
        while (nums[i] % 2 != 0) {
            ++i;
        }
        while (nums[i] % 2 == 0) {
            if (i == N) {
                break;
            }
            sum += nums[i];
            ++i;
        }
        sums[sumsIndex] = sum;
        ++sumsIndex;
    }
    int max = sums[0];
    for (int i = 1; i < sumsIndex; ++i) {
        if (max < sums[i]) {
            max = sums[i];
        }
    }
    return max;
}
int *numOfWords(char sentence[]) {
    int countEven = 0;
    int countOdd = 0;
    for (int i = 0; sentence[i] != '\0'; ++i) {
        if (sentence[i] == ' ' || sentence[i] == '\t') {
            while (sentence[i] == ' ' || sentence[i] == '\t') {
                ++i;
            }
        }
        int letterCount = 0;
        while (true) {
            if (sentence[i] == ' ' || sentence[i] == '\t' || sentence[i] == '\0') {
                break;
            }
            ++letterCount;
            ++i;
        }
        if (letterCount % 2 == 0) {
            ++countEven;
        } else if (letterCount % 2 != 0) {
            ++countOdd;
        }
    }
    int *number = new int[2];
    number[0] = countEven;
    number[1] = countOdd;
    return number;
}
int fact(int n) {
    int fact = 1;
    while (n > 0) {
        fact *= n;
        --n;
    }
    return fact;
}
double MyPow(double x, double degree) {
    double result = 1;
    while (degree > 0) {
        result *= x;
        --degree;
    }
    return result;
}
double degreeOnMinusOne(double minusOne, int degree) { return (degree % 2 == 0) ? -minusOne : minusOne; }
double MyFabs(double x) { return (x >= 0) ? x : -x; }
double MySin(double x, long n) {
    double sum = x;
    int step = 1;
    double term = x;
    const double eps = 1e-5;
    double y = 0;

    while (MyFabs(term - y) >= eps) {
        y = term;
        term = degreeOnMinusOne(-1, step) * MyPow(x, (2 * step) + 1) / fact((2 * step) + 1);
        sum += term;
        ++step;
    }

    return sum;
}

int arrayLenght(char *word) {
    int count = 0;
    for (int i = 0; word[i] != '\0'; ++i) {
        ++count;
    }
    return count;
}
int numsize(int n) {
    int len = 1;
    while (n) {
        len *= 10;
        n /= 10;
    }
    len /= 10;
    return len;
}
char *Encode(char *word) {
    int lenght = arrayLenght(word);
    const int SIZE = lenght * 4; // I put '\0' later on
    char *encoded = new char[SIZE];
    int index = 0;

    for (int i = 0; word[i] != '\0'; ++i) {
        int num = word[i];
        int numlen = numsize(num);
        while (numlen) {
            encoded[index] = num / numlen % 10 + '0';
            ++index;
            numlen /= 10;
        }
        if (word[i + 1] != '\0') {
            encoded[index] = '_';
            ++index;
        }
    }
    encoded[index] = '\0';
    return encoded;
}

#endif