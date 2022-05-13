#include <iostream>

using namespace std;

int main() {
    const int size = 50;
    int arr[size][size];
    int N,M;
    cin>>N>>M;

    for(int i = 0; i < N; i++)
    {
      for(int j = 0; j < M; j++)
      {
        cin >> arr[i][j];
      }
    }

    for(int i = 0; i < N; i++)
    {
      int sum = 0;
      for(int j = 0; j < M; j++)
      {
        sum += arr[i][j];
      }
      cout<<sum<<" ";
    }
    cout<<endl;

    return 0;
} 