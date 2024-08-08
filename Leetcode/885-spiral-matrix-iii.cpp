#include <bits/stdc++.h>
using namespace std;

class Solution {

    bool valid(int i, int j, int m, int n) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }

public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        
        int i = rStart, j = cStart, offset = 0;
        vector<int> di = {0, 1, 0, -1};
        vector<int> dj = {1, 0, -1, 0};

        int lim = rows * cols, k = 1;
        int dist = 0, turn_dist = 1;
        vector<vector<int>> coords;
        
        while(k <= lim) {

            if(valid(i, j, rows, cols)) {
                coords.push_back({i, j});
                k++;
            }

            if(dist < turn_dist) {
                dist++;
            } else { 
                offset = (offset + 1) % 4;
                dist = 1;
                turn_dist = (offset == 2 || offset == 0) ? turn_dist + 1: turn_dist;
            }

            i += di[offset];
            j += dj[offset];

        }

        return coords;

    }

};

int main() {

    int rows = 1, cols = 4, rStart = 0, cStart = 0;
    Solution s;
    vector<vector<int>> output = s.spiralMatrixIII(rows, cols, rStart, cStart);

    for(auto row : output) {
        for(auto cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

}