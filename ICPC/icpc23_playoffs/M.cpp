#include<bits/stdc++.h>

using namespace std;

int floyd(vector<vector<int>> &m) {
    
    int n = m.size();
    int c = 0;
    
    vector<vector<int>> F(n, vector<int>(n));
    vector<vector<char>> removed(n, vector<char>(n, true));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            F[i][j] = m[i][j];
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (i != j && j != k && i!= k && F[i][j] >= F[i][k]+F[k][j]) {
                    if (removed[i][j]) {
                        c++;
                        removed[i][j] = false;
                    }
                    F[i][j] = F[i][k]+F[k][j];
                }

            }
            
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(F[i][j] < m[i][j]){
                return -1;
            }
        }
        
    }

    return c;
    
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
        
    }
    
    cout << floyd(matrix) << '\n';

    return 0;
}