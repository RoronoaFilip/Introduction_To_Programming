#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int size = 50;

    int arr[size][size];
    int N,M, X;

    cin>> N >> M >> X;
    for(int i=0; i < N; ++i)
    {
      for(int j = 0; j < M; ++j)
      {
        int n;
        cin>>n;
        arr[i][j] = n;
      }
    }

    for(int i=0; i < N; ++i)
    {
      for(int j = 0; j < M; ++j)
      {
        if(arr[i][j] == X)
        {
          cout<< "True";
          return 0;
        }
        
      }
    }
    cout<< "False";
    return 0;
} 