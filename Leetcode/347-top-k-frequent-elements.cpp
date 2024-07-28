#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent1(vector<int>& nums, int k) {
        
        unordered_map<int,int> freq;
        for(int &x : nums) {
            freq[x]++;
        }

        priority_queue<pair<int, int>> freq_order;
        for(auto &[x, count] : freq) {
            freq_order.push({count, x});
        }

        vector<int> top_k;
        for(int i = 0; i < k; ++i) {
            top_k.push_back(freq_order.top().second);
            freq_order.pop();
        }

        return top_k;

    }

    vector<int> topKFrequent2(vector<int>& nums, int k) {

        int n = nums.size();
        vector<unordered_set<int>> freq_groups(n + 1);

        unordered_map<int,int> freq;
        for(int &x : nums) {
            
            if(freq[x] > 0) {
                freq_groups[freq[x]].erase(x);
            }

            freq[x]++;

            freq_groups[freq[x]].insert(x);

        }

        vector<int> top_k;
        for(int i = n; i >= 1 && top_k.size() < k; --i) {

            if(!freq_groups[i].empty()) {
                for(auto &x : freq_groups[i]) {
                    top_k.push_back(x);
                }
            }

        }

        return top_k;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();
        vector<vector<int>> freq_groups(n + 1);

        unordered_map<int,int> freq;
        for(int &x : nums) {
            freq[x]++;
        }

        for(auto &[x, count] : freq) {
            freq_groups[count].push_back(x);
        }

        vector<int> top_k;
        for(int i = n; i >= 1 && top_k.size() < k; --i) {

            if(!freq_groups[i].empty()) {
                for(auto &x : freq_groups[i]) {
                    top_k.push_back(x);
                }
            }

        }

        return top_k;
    }
};

int main() {
    
    Solution s;

    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    vector<int> top_k = s.topKFrequent(nums, k);

    for(int &x : top_k) {
        cout << x << " ";
    }
    cout << '\n';

}