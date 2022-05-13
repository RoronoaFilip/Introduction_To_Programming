#include <iostream>
#include <vector>

using namespace std;

// Задача: Редицата на Фибоначи 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, … се дефинира по следния начин: първият елемент е 0,
// вторият е 1, а всеки следващ се получава като сума от предходните два. Напишете рекурсивна програма,
// която пресмята n-тия член на редицата на Фибоначи.
int myFib(const int n) {
    int num = 1;
    int x1 = 0;
    int x2 = 1;
    while (num != n) {
        int temp = x2;
        x2 = x2 + x1;
        x1 = temp;
        ++num;
    }
    return x1;
}
int fib(const int n) {
    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

// Задача Да се дефинира рекурсивна функция, която изчислява биномния коефициент:
// C(0, n) = 1
// C(m, 0) = 1
// C(n, n) = 1
// C(m, n) = C(m-1, n-1) + C(m-1, n)

int binCoef(const int m, const int n) {
    if (m == 0 || n == 0 || m == n) {
        return 1;
    }
    return binCoef(m - 1, n - 1) + binCoef(m - 1, n);
}

// Задача Да се напише рекурсивна функция, която отпечатва в обратен ред цифрите на дадено цяло положително число.
void reverseNum(const int n) {
    if (n <= 9) {
        cout << n;
        return;
    }
    cout << n % 10;
    reverseNum(n / 10);
}

// Задача Съставете рекурсивна подпрограма, която намира сумата от цифрите на дадено цяло положително число.
int sum(const int n) {
    if (n <= 9) {
        return n;
    }
    return n % 10 + sum(n / 10);
}

// Задача Да се напише рекурсивна функция, която установява, дали в записа на естественото число n се съдържа цифрата k.
bool findDigit(const int n, const int k) {
    if (n <= 9) {
        return n == k;
    }
    if (n % 10 == k) {
        return true;
    }
    return findDigit(n / 10, k);
}

// Задача Да се напише рекурсивна програма, която проверява дали елементът x принадлежи на редицата а0, а1, …, аn-1
// (последователно търсене)
bool findElement(const int x, int arr[], const int size, const int i) {
    if (size == 0) {
        return false;
    }
    if (size == 1) {
        return x == arr[0];
    }
    if (size == i) {
        return false;
    }
    if (x == arr[i]) {
        return true;
    }
    return findElement(x, arr, size, i + 1);
}

// Задача Да се напише рекурсивна програма, която проверява дали редицата а0, а1, …, аn-1 е монотонно растяща.
bool isMonotone(int arr[], const int size, const int i) {
    if (size == 1) {
        return false;
    }
    if (size - 1 == i) {
        return false;
    }
    if (arr[i] > arr[i + 1]) {
        return false;
    }
    return isMonotone(arr, size, i + 1);
}

// Задача Да се напише рекурсивна програма, която проверява дали елементът x принадлежи на сортирана редицата а0, а1, …,
// аn-1 (двоично търсене) {1, 3, 5, 7, 10}
bool findElementBinary(const int x, int arr[], const int left, const int right) {
    if (left >= right) {
        return false;
    }
    int mid = (left + right) / 2;
    if (arr[mid] == x) {
        return true;
    } else if (arr[mid] < x) {
        return findElementBinary(x, arr, mid + 1, right);
    }
    return findElementBinary(x, arr, left, mid - 1);
}

// Задача Да се напише рекурсивна програма, която проверява дали даден низ е палиндром.
// "a" -> true
// "..." -> "a" + "..." + "a"
bool isPalindrome(string str) {
    if (str.size() == 1) {
        return true;
    }
    if (str[0] != str[str.size() - 1]) {
        return false;
    }
    return isPalindrome(str.substr(1, str.size() - 2));
}

bool isPalindrome(const string &str, const int i) {
    if (str.size() == 1) {
        return true;
    }
    if (str.size() / 2 >= i) {
        return true;
    }
    if (str[i] != str[str.size() - 1 - i]) {
        return false;
    }
    return isPalindrome(str, i + 1);
}

// Задача Да се напише рекурсивна програма, която проверява дали редицата а0, а1, …, аn-1 се състои от различни елементи.
bool isDifferent(int arr[], const int size, const int i = 0) {
    // Условие за край
    if (i == size) {
        return true;
    }
    // „Тяло на рекурсията“
    for (int j = i; j < size - 1; ++j) {
        if (arr[j] == arr[j + 1]) {
            return false;
        }
    }
    // Рекурсивно извикване („Края на тялото на рекурсията“)
    return isDifferent(arr, size, i + 1);
}

// Задача Да се напише рекурсивна програма, която добавя елемент в сортиран масив, като запазва наредбата на елементите.
void insertElement(const int x, vector<int> &arr, const int i = 0) {
    if (i == arr.size()) {
        arr.push_back(x);
        return;
    }
    if (arr[i] > x) {
        // Вмъкваме елемента x преди arr[i]
        arr.insert(arr.begin() + i, x);
        return;
    }
    insertElement(x, arr, i + 1);
}

int main() {
    int n = 7;
    cout << myFib(n);
    return 0;
}
