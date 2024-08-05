class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        
        unordered_map<string,int> freq;
        for(string &s : arr) {
            freq[s]++;
        }

        int i = 0;
        for(string &s : arr) {

            if(freq[s] < 2) {
                i++;
            }

            if(i == k) {
                return s;
            }

        }

        return "";
        
    }
};