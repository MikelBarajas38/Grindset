class Solution {

    bool valid(int i, int j, int m, int n) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }

public:
    vector<vector<int>> generateMatrix(int n) {
        
        int i = 0, j = 0, offset = 0;
        vector<int> di = {0, 1, 0, -1};
        vector<int> dj = {1, 0, -1, 0};

        int lim = n * n, k = 1;
        vector<vector<int>> matrix(n, vector<int>(n));
        
        while(k <= lim) {

            if(valid(i, j, n, n) && !matrix[i][j]) {
                matrix[i][j] = k;
                k++;
            } else { 
                i -= di[offset];
                j -= dj[offset];
                offset = (offset + 1) % 4;
            }

            i += di[offset];
            j += dj[offset];

        }

        return matrix;

    }
};