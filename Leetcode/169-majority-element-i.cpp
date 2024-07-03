class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int mayority_element, count = 0;

        for(int &x : nums) {
            if(count == 0) {
                mayority_element = x;
            }
            count += (mayority_element == x) ? 1 : -1;
        }

        return mayority_element;

    }

    int majorityElement1(vector<int>& nums) {

        map<int,int> freq;
        for(int &x : nums) {
            freq[x]++;
        }

        int most_freq = -1, best_freq = 0;
        for(const auto& [key, value] : freq) {
            if(freq[key] > best_freq) {
                best_freq = freq[key];
                most_freq = key;
            }
        }

        return most_freq;
    }
};