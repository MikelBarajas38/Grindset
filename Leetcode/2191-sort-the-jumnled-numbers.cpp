class Solution {

    int get_mapped_representation(int x, vector<int> &mapping) {

        if(x == 0) {
            return mapping[0];
        }

        int out = 0, pos = 1;
        while(x > 0) {
            out += mapping[(x % 10)] * pos;
            x /= 10;
            pos *= 10;
        }
        return out;
        
    }

public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {

        int n = nums.size();

        vector<int> indices;
        vector<int> mapped_nums;

        for(int i = 0; i < n; ++i) {
            indices.push_back(i);
            mapped_nums.push_back(get_mapped_representation(nums[i], mapping));
        }

        sort(indices.begin(), indices.end(), [&] (int l, int r) {
            return mapped_nums[l] < mapped_nums[r];
        });

        vector<int> sorted_nums;
        for(int i = 0; i < n; ++i) {
            sorted_nums.push_back(nums[indices[i]]);
        }

        return sorted_nums;

    }
};