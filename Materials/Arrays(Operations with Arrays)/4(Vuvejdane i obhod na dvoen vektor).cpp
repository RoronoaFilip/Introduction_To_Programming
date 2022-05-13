#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> arr;
    int N,M;
    cin >> N >> M;
    
    for(int i = 0; i<N; i++){
      arr.push_back(vector<int>());
      for(int j=0;j<M;j++)
      {
        int n;
        cin >> n;
        arr[i].push_back(n);
      }
    }

    bool isThereNegative = false;
    for (int i = 0;i<N;i++){
      for(int j = 0;j<M;j++)
      {
        if (arr[i][j]<0)
        {
          isThereNegative = true;
          break;
        }
      }
      if (isThereNegative) break;
    }

    cout << isThereNagative ? "true" : "false";

    return 0;
} 