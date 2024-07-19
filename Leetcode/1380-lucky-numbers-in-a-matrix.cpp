class Solution {
private:

    vector<int> get_row_mins(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        vector<int> mins(m);

        for(int i = 0; i < m; i++) {
            mins[i] = *min_element(matrix[i].begin(), matrix[i].end());
        }

        return mins;

    }

    vector<int> get_col_maxs(vector<vector<int>>& matrix) {

        int n = matrix[0].size();
        int m = matrix.size();

        vector<int> maxs(n, 0);
        for(int j = 0; j < n; j++) {
           for(int i = 0; i < m; i++) {
                maxs[j] = max(maxs[j], matrix[i][j]);
           }
        }

        return maxs;

    }

    int get_max_row_min(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        vector<int> mins(m);

        for(int i = 0; i < m; i++) {
            mins[i] = *min_element(matrix[i].begin(), matrix[i].end());
        }

        return *max_element(mins.begin(), mins.end());

    }

    int get_min_col_max(vector<vector<int>>& matrix) {

        int n = matrix[0].size();
        int m = matrix.size();

        vector<int> maxs(n, 0);
        for(int j = 0; j < n; j++) {
           for(int i = 0; i < m; i++) {
                maxs[j] = max(maxs[j], matrix[i][j]);
           }
        }

        return *min_element(maxs.begin(), maxs.end());

    }

public:
    vector<int> luckyNumbers1 (vector<vector<int>>& matrix) {

        int n = matrix[0].size();
        int m = matrix.size();
        
        vector<int> mins = get_row_mins(matrix);
        vector<int> maxs = get_col_maxs(matrix);

        vector<int> lucky_nums;
        for(int i = 0; i < m; i++) {
           for(int j = 0; j < n; j++) {
                if(mins[i] == maxs[j]) {
                    lucky_nums.push_back(mins[i]);
                }
           }
        }

        return lucky_nums;

    }

    vector<int> luckyNumbers (vector<vector<int>>& matrix) {

        int n = matrix[0].size();
        int m = matrix.size();

        int min_col_max = get_min_col_max(matrix), max_row_min = get_max_row_min(matrix);
        if(min_col_max == max_row_min) {
            return {min_col_max};
        }

        return {};

    }
};