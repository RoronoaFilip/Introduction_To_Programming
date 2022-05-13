#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> matrix;
    int X;
    cin>>X;
    for (int i=0; i < X; ++i)
    {
        matrix.push_back(vector<int> ());
        for ( int j = 0; j < X; ++j)
        {
          int n;
          cin>> n;
          matrix[i].push_back(n);
        }
    }

    for(int i = 0; i < X; ++i)
    {
        if (matrix[i][i] >= 0)
        {
          cout << matrix[i][i] << " ";
        }
    }
    
    return 0;
} 