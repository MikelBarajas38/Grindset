#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {

        const int MOD = 1e9 + 7;

        vector<int> prefix_sum(n + 1);
        for(int i = 1; i <= n; ++i) {
            prefix_sum[i] = prefix_sum[i-1]+ nums[i-1];
            prefix_sum[i] %= MOD;
        }

        vector<int> subarray_sums;
        for(int i = 1; i <= n; ++i) {
            for(int j = i; j <= n; ++j) {
                int subarray_sum = prefix_sum[j] - prefix_sum[i - 1];
                subarray_sums.push_back(subarray_sum); 
            }
        }

        sort(subarray_sums.begin(), subarray_sums.end());

        int sum = 0;
        for(int i = left - 1; i < right; ++i) {
            sum += subarray_sums[i];
            sum %= MOD;
        }

        return sum;

    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3,4};
    int n = 4;
    int left = 1;
    int right = 5;
    cout << s.rangeSum(nums, n, left, right) << '\n';
}