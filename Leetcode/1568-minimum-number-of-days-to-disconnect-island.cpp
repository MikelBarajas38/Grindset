#include <bits/stdc++.h>
using namespace std;

/*
approach 1: flood fill brute force
approach 2: tarjan's algorithm (TODO)
*/

class Solution {

    bool valid(vector<vector<int>> &grid, int i, int j) {
        return(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size());
    }

    void flood(vector<vector<int>> &grid, int i, int j) {

        vector<int> di = {0, 0, 1, -1};
        vector<int> dj = {1, -1, 0, 0};

        grid[i][j] = 0;

        for(int k = 0; k < 4; ++k) {
            int ni =  i + di[k];
            int nj =  j + dj[k];
            if(valid(grid, ni, nj) && grid[ni][nj] == 1) {
                flood(grid, ni, nj);
            }
        }

    }

public:
    int minDays(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> test_grid = grid;
        int island_count = 0;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(test_grid[i][j] == 1) {
                    island_count++;
                    flood(test_grid, i, j);
                }
            }
        }

        if(island_count != 1) {
            return 0;
        }

        vector<int> di = {0, 0, 1, -1};
        vector<int> dj = {1, -1, 0, 0};

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 1) {

                    test_grid = grid;

                    test_grid[i][j] = 0;

                    int flooded = 0;
                    for(int k = 0; k < 4; ++k) {
                        int ni =  i + di[k];
                        int nj =  j + dj[k];
                        if(valid(test_grid, ni, nj) && test_grid[ni][nj] == 1) {
                            flooded++;
                            flood(test_grid, ni, nj);
                        }
                    }

                    if(flooded != 1) {
                        return 1;
                    }

                }
            }
        }

        // disconnect a corner
        return 2;
        
    }
};

int main() {

    vector<vector<int>> grid = {{1,1,0,1,1},{1,1,1,1,1},{1,1,0,1,1},{1,1,0,1,1}};
    Solution s;
    cout << s.minDays(grid) << '\n';

    return 0;
}