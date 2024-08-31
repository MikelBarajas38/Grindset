class Solution {

    bool is_valid(int i, int j, vector<vector<int>>& grid) {
        return (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size());
    }

    bool is_subisland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {

        grid2[i][j] = 0;

        int di[] = {1, -1, 0, 0};
        int dj[] = {0, 0, 1, -1};

        bool in_grid1 = true;
        for(int k = 0; k < 4; ++k) {
            int ki = i + di[k], kj = j + dj[k];
            if(is_valid(ki, kj, grid1) && grid2[ki][kj]) {
                in_grid1 &= grid1[ki][kj] && is_subisland(grid1, grid2, ki, kj);
            }
        }

        return in_grid1;

    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        int n = grid1.size();
        int m = grid1[0].size();

        int count = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid1[i][j] && grid2[i][j]) {
                    count += is_subisland(grid1, grid2, i, j);
                }
            }
        }
        
        return count;
    }
};