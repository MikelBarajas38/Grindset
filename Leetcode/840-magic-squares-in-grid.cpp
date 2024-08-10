class Solution {

    bool is_magic_square(vector<vector<int>>& grid, int i, int j) {

        unordered_set<int> used;
        for(int ii = i; ii < i + 3; ++ii) {
            for(int jj = j; jj < j + 3; ++jj) {
                if(grid[ii][jj] > 9 || grid[ii][jj] < 1) return false;
                used.insert(grid[ii][jj]);
            }
        }

        if(used.size() != 9) return false;

        int row_1 = grid[i][j] + grid[i][j+1] + grid[i][j+2];

        int row_2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
        int row_3 = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];

        if(row_1 != row_2 || row_1 != row_3) { 
            return false;
        }

        int col_1 = grid[i][j] + grid[i+1][j] + grid[i+2][j];
        int col_2 = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
        int col_3 = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];
        
        if(row_1 != col_1 || row_1 != col_2 || row_1 != col_3) { 
            return false;
        }

        int diag_1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
        int diag_2 = grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2];
        
        if(row_1 != diag_1 || row_1 != diag_2) { 
            return false;
        }

        return true;

    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int magic_squares = 0;
        for(int i = 0; i < n - 2; ++i) {
            for(int j = 0; j < m - 2; ++j) {
                if(is_magic_square(grid, i, j)) {
                    magic_squares++;
                }
            }
        }

        return magic_squares;
        
    }
};