class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> elements;
        
        for(int &x : nums) {
            if(elements.count(x)) {
                return true;
            }
            elements.insert(x);
        }

        return false;

    }
};