#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int removeElement1(vector<int>& nums, int val) {
        
        vector<int> val_removed;
        int k = 0;

        for(int &x : nums) {
            if (x != val) {
                val_removed.push_back(x);
            }
        }

        nums = val_removed;
        return nums.size();
    }

    int removeElement(vector<int>& nums, int val) {
        
        int r = nums.size() - 1;

        while(r >= 0 && nums[r] == val) r--;

        for(int i = 0; i <= r; i++) {
            if(nums[i] == val) {
                swap(nums[i], nums[r]);
                while(r >= 0 && nums[r] == val) r--;
            }
        }     

        return r + 1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,2,2,3};
    cout << s.removeElement(nums, 3) << '\n';

    vector<int> nums2 = {0,1,2,2,3,0,4,2};
    cout << s.removeElement(nums2, 2) << '\n';

    vector<int> nums3 = {4,2,0,2,2,1,4,4,1,4,3,2};
    cout << s.removeElement(nums3, 4) << '\n';
}