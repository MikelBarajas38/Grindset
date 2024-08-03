#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {

        int n = nums.size();
        int ones = accumulate(nums.begin(), nums.end(), 0);

        int subarray_zeros = 0;
        for(int i = 0; i < ones; ++i) {
            if(nums[i] == 0) {
                subarray_zeros++;
            }
        }

        int min_zeros = subarray_zeros;
        for(int i = 1; i < n; ++i) {

            int start = i - 1;
            int end = (i + ones - 1) % n;

            if(nums[start] == 0) {
                subarray_zeros--;
            }

            if(nums[end] == 0) {
                subarray_zeros++;
            }

            min_zeros = min(min_zeros, subarray_zeros);

        }

        return min_zeros;
        
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,1,0,0,1,0,0,0,1};
    cout << sol.minSwaps(nums) << '\n';
    return 0;
}