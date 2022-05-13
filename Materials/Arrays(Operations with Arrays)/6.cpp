#include <iostream>
using namespace std;
int main(){

 int arr[50][50];
    int N, M;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
        }
    }
    int sum=0;
     for(int i = 0; i < N; i++)
    {
        if(arr[i][i]>=0){
            cout<<arr[i][i]<<" ";
        }
    }

    return 0;
}