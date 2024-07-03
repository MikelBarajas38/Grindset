class Solution {
public:

    vector<int> majorityElement(vector<int>& nums) {

        int m1 = -1, c1 = 0, m2 = -1, c2 = 0;
        for(int &x : nums) {

            if(c1 == 0 && m2 != x) {
                m1 = x;
                c1 = 1;
            } else if(c2 == 0 && m1 != x){
                m2 = x;
                c2 = 1;
            } else if(m1 == x){
                c1++;
            } else if(m2 == x) {
                c2++;
            } else {
                c1--;
                c2--;
            }
            
        }

        int test_c1 = 0, test_c2 = 0;
        for(int &x : nums) {

            if(x == m1) {
                test_c1++;
            } else if(x == m2) {
                test_c2++;
            }

        }

        int n = nums.size();
        vector<int> majority_elements;

        if(test_c1 > n / 3) majority_elements.push_back(m1);
        if(test_c2 > n / 3) majority_elements.push_back(m2);

        return majority_elements;
    }

    vector<int> majorityElement1(vector<int>& nums) {

        map<int,int> freq;
        for(int &x : nums) {
            freq[x]++;
        }

        int n = nums.size();
        vector<int> majority_elements;
        for(const auto& [key, value] : freq) {
            if(value > n / 3) {
                majority_elements.push_back(key);
            }
        }

        return majority_elements;
    }
};