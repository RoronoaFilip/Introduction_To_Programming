#include <iostream>
#include <vector>

using namespace std;
// Задача Триъгълна матрица наричаме такава квадратна матрица, която има само нули под или над главния или вторичния си диагонал. Даден е двумерен масив с nxn елемента. Да се провери дали е триъгълна матрица.
bool zerosBelowMainDiagonal(const vector<vector<int>>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool zerosAboveMainDiagonal(const vector<vector<int>>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i + 1; j < arr[i].size(); ++j) {
            if (arr[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool zerosBelowDiagonal(const vector<vector<int>>& arr) {
    int size = arr.size();
    for (int i = 0; i < size; ++i) {
        for (int j = size - i; j < size; ++j) {
            if (arr[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool zerosAboveDiagonal(const vector<vector<int>>& arr) {
    int size = arr.size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> arr(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int temp;
            cin >> temp;
            arr[i].push_back(temp);
        }
    }
    
    bool isTriangular = zerosAboveDiagonal(arr) ||
                        zerosAboveMainDiagonal(arr) ||
                        zerosBelowDiagonal(arr) ||
                        zerosBelowMainDiagonal(arr);

    cout << isTriangular;
    return 0;
}