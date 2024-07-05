class Solution {
public:

    int climbStairs1(int n) {
        
        int f1 = 0, f2 = 1, ans;

        for(int i = 0; i <= n; i++) {
            ans = f1 + f2;
            f2 = f1;
            f1 = ans;
        }

        return ans;
    }

    int climbStairs(int n) {
        
        vector<int> dp(n + 1, 1);
        for(int i = 2; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
        
    }

};