#include <bits/stdc++.h>
using namespace std;

/*

                  0 1 2 3 4 5 6 7
                 "a a b a b b a b"
prefix_sum_b = [0 0 0 1 1 2 3 3 4]
suffix_sum_a =   [4 3 2 2 1 1 1 0 0]

*/

class Solution {
public:
    int minimumDeletions(string s) {

        int n = s.length();
        
        vector<int> preffix_sum_b(n + 1);
        vector<int> suffix_sum_a(n + 1);

        for(int i = 1; i <= n; ++i) {
            preffix_sum_b[i] = s[i-1] == 'b' ? 1 : 0;
            preffix_sum_b[i] += preffix_sum_b[i-1];
        }

        for(int i = n - 1; i >= 0; --i) {
            suffix_sum_a[i] = s[i] == 'a' ? 1 : 0;
            suffix_sum_a[i] += suffix_sum_a[i+1];
        }

        int min_deletions = INT_MAX;
        for(int i = 0; i < n; ++i) {
            int misplaces_a = suffix_sum_a[i+1];
            int misplaces_b = preffix_sum_b[i];
            min_deletions = min(min_deletions, misplaces_a + misplaces_b);
        }

        return min_deletions;

    }
};

int main() {
    Solution s;
    string str = "aababbab";
    cout << s.minimumDeletions(str) << '\n';
    return 0;
}