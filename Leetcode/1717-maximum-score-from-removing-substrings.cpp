#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int count_and_remove_pattern(string &s, char first, char second) {

        string match = "";
        int count = 0;

        for(char &c : s) {
            if(c == second && !match.empty() && match.back() == first) {
                match.pop_back();
                count++;
            } else {
                match.push_back(c);
            }
        }

        s = match;

        return count;

    }

    int maximumGain(string s, int x, int y) {
        
        int total_score = 0;
        if(x > y) {
            total_score += count_and_remove_pattern(s, 'a', 'b') * x;
            total_score += count_and_remove_pattern(s, 'b', 'a') * y;
        } else {
            total_score += count_and_remove_pattern(s, 'b', 'a') * y;
            total_score += count_and_remove_pattern(s, 'a', 'b') * x;
        }

        return total_score;

    }
};

int main() {
    Solution s;
    cout << s.maximumGain("ababab", 1, 3) << '\n';
    cout << s.maximumGain("cdbcbbaaabab", 4, 5) << '\n';
    return 0;
}