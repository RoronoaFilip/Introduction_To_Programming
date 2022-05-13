#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> arr;

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        arr.push_back(vector<int>());
        for (int j = 0; j < M; ++j) {
            int temp;
            cin >> temp;
            arr[i].push_back(temp);
        }
    }

    for (vector<int>& line: arr) {
        int count = 0;
        for (int item: line) {
            if (item < 0) {
                ++count;
            }
        }
        cout << count << " ";
    }
    cout << endl;

    return 0;
} 