#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto p = nums.begin() + k - 1;
        nth_element(nums.begin(), p, nums.end(), greater{});
        return nums[k - 1];
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,2,1,5,6,4};
    cout << s.findKthLargest(nums, 6) << '\n';

    vector<int> nums2 = {-1, 2, 0};
    cout << s.findKthLargest(nums2, 3) << '\n';
}