#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int l = 0, r = matrix.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (matrix[m][0] > target) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        int row = l > 0 && matrix[l][0] > target ? 
                  l - 1 
                : l;
                
        l = 0, r = matrix[row].size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (matrix[row][m] == target) {
                return true;
            } else if (matrix[row][m] > target){
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return false;

    }

    
};