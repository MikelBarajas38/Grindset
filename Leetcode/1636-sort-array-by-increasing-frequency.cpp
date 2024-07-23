class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        int n = nums.size();

        unordered_map<int,int> freq;
        for(int &x : nums) {
            freq[x]++;
        }

        vector<pair<int,int>> nums_with_freq;
        for(int i = 0; i < n; ++i) {
            nums_with_freq.push_back({freq[nums[i]], nums[i]});
        }

        sort(nums_with_freq.begin(), nums_with_freq.end(), [] (auto &a, auto &b) {
            if(a.first == b.first){
                return a.second > b.second;
            }
            return a.first < b.first;
        });

        vector<int> sorted_nums;
        for(auto &[freq, val] : nums_with_freq) {
            sorted_nums.push_back(val);
        }

        return sorted_nums;

    }
};