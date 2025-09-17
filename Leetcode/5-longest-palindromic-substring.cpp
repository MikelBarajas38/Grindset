class Solution {

    pair<int, int> find_palindrome(int l, int r, string &s) {
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return {l+1, r-1};
    }

public:
    string longestPalindrome(string s) {

        int n = s.size();
        int max_size = 1, bl = 0, br = 0;
        for(int i = 0; i < n - 1; ++i) {

            if(s[i] == s[i+1]) {
                auto [l, r] = find_palindrome(i, i+1, s);
                int palindrome_size = r - l + 1;
                if(palindrome_size > max_size) {
                    max_size = palindrome_size;
                    bl = l;
                    br = r;
                }
            }

            if(i > 0 && s[i-1] == s[i+1]) {
                auto [l, r] = find_palindrome(i-1, i+1, s);
                int palindrome_size = r - l + 1;
                if(palindrome_size > max_size) {
                    max_size = palindrome_size;
                    bl = l;
                    br = r;
                }
            }

        }

        return s.substr(bl, max_size);

    }
};