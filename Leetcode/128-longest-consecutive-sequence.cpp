class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_map<int, int> sequences; // val, len of curr sequence

        int max_len = 0;
        for(int &x : nums) {
            
            if(sequences.count(x)) continue;

            int left = sequences.count(x-1) ? sequences[x-1] : 0;
            int right = sequences.count(x+1) ? sequences[x+1] : 0;

            int len = left + 1 + right;

            sequences[x] = len;
            sequences[x-left] = len;
            sequences[x+right] = len;

            max_len = max(max_len, len);

        }

        return max_len;

    }
};