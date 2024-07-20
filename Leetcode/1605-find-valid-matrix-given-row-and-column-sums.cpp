/*

    0  0

    3  0   0
    1  7   0



*/

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {

        int n = rowSum.size();
        int m = colSum.size();

        vector<vector<int>> restored_matrix(n, vector<int>(m));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                int restored_val = min(rowSum[i], colSum[j]);
                restored_matrix[i][j] = restored_val;
                rowSum[i] -= restored_val;
                colSum[j] -= restored_val;

            } 
        }

        return restored_matrix;
        
    }
};