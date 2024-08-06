#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes1(string word) {
        
        vector<int> freq(26);
        for(char &c : word) {
            freq[c - 'a']++;
        }

        vector<int> indexes(26);
        for(int i = 0; i < 26; ++i) {
            indexes[i] = i;
        }

        sort(indexes.begin(), indexes.end(), [&] (int l, int r) {
            return freq[l] > freq[r];
        });

        vector<int> cost(26);

        for(int i = 0; i < 8; ++i) {
            cost[indexes[i]] = 1;
        }

        for(int i = 8; i < 16; ++i) {
            cost[indexes[i]] = 2;
        }

        for(int i = 16; i < 24; ++i) {
            cost[indexes[i]] = 3;
        }

        for(int i = 24; i < 26; ++i) {
            cost[indexes[i]] = 4;
        }

        int total_cost = 0;
        for(char &c : word) {
            total_cost += cost[c - 'a'];
        }

        return total_cost;

    }

    int minimumPushes(string word) {
        
        vector<int> freq(26);
        for(char &c : word) {
            freq[c - 'a']++;
        }

        sort(freq.rbegin(), freq.rend());

        int total_cost = 0;

        for(int i = 0; i < 26; ++i) {
            total_cost += (i / 8 + 1) * freq[i];
        }
        
        return total_cost;

    }
};

int main() {
    Solution s;
    string word = "aabbccddeeffgghhiiiiii";
    cout << s.minimumPushes(word);
}