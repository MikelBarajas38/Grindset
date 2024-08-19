#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int k = nums.size();

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> window;
        int window_max = -1;
        for(int i = 0; i < k; ++i) {
            window.push({nums[i][0], i});
            window_max = max(window_max, nums[i][0]);
        }

        vector<int> min_range = {-1, -1};
        int min_range_value = INT_MAX;
        vector<int> current_index(k);

        while(window.size() == k) {

            int window_min = window.top().first;
            int i = window.top().second;
            window.pop();

            int current_range = window_max - window_min;
            if(current_range < min_range_value) {
                min_range = {window_min, window_max};
                min_range_value = current_range;
            }

            current_index[i]++;

            if(current_index[i] < nums[i].size()) {
                int next = nums[i][current_index[i]];
                window.push({next, i});
                window_max = max(window_max, next);
            }
            
        }

        return min_range;

    }
};

int main() {

    Solution s;

    vector<vector<int>> nums = {
        {4,10,15,24,26},
        {0,9,12,20},
        {5,18,22,30}
    };

    vector<int> min_range = s.smallestRange(nums);

    cout << '[' << min_range[0] << ',' << min_range[1] << ']' << '\n';

}