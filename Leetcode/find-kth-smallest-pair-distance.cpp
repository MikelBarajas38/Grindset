#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> pair_distances(10001);
        for(int i = 0; i < n - 1; ++i) {
            for(int j = i + 1; j < n; ++j) {
                int dist = abs(nums[i] - nums[j]);
                pair_distances[dist]++;
            }
            
        }

        int kth_dist = 0;
        for(int i = 0; i < 10001; ++i) {
            if(pair_distances[i] >= k) {
                kth_dist = i;
                break;
            }
            k -= pair_distances[i];
        }

        return kth_dist;
        
    }
};

int main() {

    Solution s;
    vector<int> nums = {1,3,1,1,3,1};
    int k = 1;
    cout << s.smallestDistancePair(nums, k) << '\n';

    return 0;
}