#include <bits/stdc++.h>
using namespace std;

class Solution {

    string mirror(string s, bool odd) {

        string mirrored = s;
        reverse(s.begin(), s.end());

        if(odd) {
            mirrored.pop_back();
        }  

        return mirrored + s; 

    }

    long long get_diff(string a, string b) {
        unsigned long long a_ull = stoull(a);
        unsigned long long b_ull = stoull(b);

        if(a_ull > b_ull) {
            return a_ull - b_ull;
        } 

        return b_ull - a_ull;
    }

public:
    string nearestPalindromic(string n) {
        
        int size = n.size();
        long long rhs = stoi(n.substr(0, (size + 1) / 2));

        if(size == 1) {
            int prev = stoi(n) - 1;
            return prev < 0 ? "1" : to_string(prev); 
        }

        string prev_mag = string(size - 1, '9');
        string next_mag = '1' + string(size - 1, '0') + '1';
        string prev = mirror(to_string(rhs - 1), size % 2);
        string next = mirror(to_string(rhs + 1), size % 2);
        string curr = mirror(to_string(rhs), size % 2);

        vector<string> candidates = {next_mag, next, prev, prev_mag, curr};

        if(curr == n) {
            candidates.pop_back();
        } 

        sort(candidates.begin(), candidates.end());

        string winner;
        long long min_diff = 1e18;
        for(string &c : candidates) {
            long long diff = get_diff(c, n);
            if(min_diff > diff || (min_diff == diff && stoull(c) < stoull(winner))) {
                winner = c;
                min_diff = diff;
            }
        }

        return winner;

    }
};

int main() {
    Solution sol;
    string n = "10";
    cout << sol.nearestPalindromic(n) << '\n';
    return 0;
}