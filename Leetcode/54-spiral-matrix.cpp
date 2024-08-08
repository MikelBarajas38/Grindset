class Solution {

    bool valid(int i, int j, int m, int n) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size(), n = matrix[0].size();
        
        int i = 0, j = 0, offset = 0;
        vector<int> di = {0, 1, 0, -1};
        vector<int> dj = {1, 0, -1, 0};

        vector<vector<bool>> used(m, vector<bool>(n, false));
        vector<int> output;
        int lim = m * n;
        
        while(output.size() < lim) {

            if(valid(i, j, m, n) && !used[i][j]) {
                output.push_back(matrix[i][j]);
                used[i][j] = true;
            } else { 
                i -= di[offset];
                j -= dj[offset];
                offset = (offset + 1) % 4;
            }

            i += di[offset];
            j += dj[offset];

        }

        return output;

    }
};