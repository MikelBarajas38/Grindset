#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {

        int n = points.size(), m = points[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m));

        for(int j = 0; j < m; ++j) {
            dp[0][j] = points[0][j];
        }

        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                long long max_score = -1;
                for(int k = 0; k < m; ++k) {
                    max_score = max(max_score, dp[i-1][k] - abs(k - j));
                }
                dp[i][j] = points[i][j] + max_score;
            }
        }

        return *max_element(dp[n-1].begin(), dp[n-1].end());
        
    }
};

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {

        int n = points.size(), m = points[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m));

        for(int j = 0; j < m; ++j) {
            dp[0][j] = points[0][j];
        }

        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                long long max_score = -1;
                for(int k = 0; k < m; ++k) {
                    max_score = max(max_score, dp[i-1][k] - abs(k - j));
                }
                dp[i][j] = points[i][j] + max_score;
            }
        }

        return *max_element(dp[n-1].begin(), dp[n-1].end());
        
    }
};
*/

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {

        int n = points.size(), m = points[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m));

        for(int j = 0; j < m; ++j) {
            dp[0][j] = points[0][j];
        }

        for(int i = 1; i < n; ++i) {

            vector<long long> left(m), right(m);

            left[0] = dp[i-1][0];

            for(int j = 1; j < m; ++j) {
                left[j] = max(left[j-1] - 1, dp[i-1][j]);
            }

            right[m-1] = dp[i-1][m-1];
            for(int j = m-2; j >= 0; --j) {
                right[j] = max(right[j+1] - 1, dp[i-1][j]);
            }

            for(int j = 0; j < m; ++j) {
                dp[i][j] = points[i][j] + max(left[j], right[j]);
            }

        }

        return *max_element(dp[n-1].begin(), dp[n-1].end());

    }
};

int main() {

    Solution s;

    vector<vector<int>> points = {{5,2,1,2},{2,1,5,2},{5,5,5,0}};

    cout << s.maxPoints(points) << '\n';

}