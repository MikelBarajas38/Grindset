class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        unordered_map<int,int> prev;
        vector<int> ans;

        for(int i = 0; i < n; ++i) {
            
            int comp = target - nums[i];

            if(prev.count(comp)) {
                ans = {prev[comp], i};
                break;
            }

            prev[nums[i]] = i;

        }

        return ans;
        
    }
};