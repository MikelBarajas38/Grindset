class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        return is_permutation(arr.begin(), arr.end(), target.begin());

    }
};