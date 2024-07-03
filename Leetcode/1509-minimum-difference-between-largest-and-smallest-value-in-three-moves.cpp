/*

20 75 81 82 95

81 81 81 82 95

*/

class Solution {
public:
    int minDifference(vector<int>& nums) {
        
        if(nums.size() < 5) {
            return 0;
        }
 
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int best_diff = 2e9;
        for(int i = 0; i <= 3; i++) {
            int move_diff = nums[n-1-i] - nums[3-i];
            best_diff = min(best_diff, move_diff);
        }

        return best_diff;
    }
};