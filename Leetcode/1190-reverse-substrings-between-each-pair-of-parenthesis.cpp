#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void reverse_substrings(string &s, string &out, int l, int r, bool reverse) {

        while(l <= r) {

            if (reverse) {
                if(s[r] == ')') {
                    int next_l = l;
                    while(s[next_l] != '(') {
                        next_l++;
                    }
                    reverse_substrings(s, out, next_l+1, r-1, !reverse);
                    r = next_l-1;
                } else {
                    out += s[r];
                    r--;
                }
            } else {
                if(s[l] == '(') {
                    int next_r = r;
                    while(s[next_r] != ')') {
                        next_r--;
                    }
                    reverse_substrings(s, out, l+1, next_r-1, !reverse);
                    l = next_r+1;
                } else {
                    out += s[l];
                    l++;
                }
            }
        }

    }

    string reverseParenthesesBad(string s) {
        int n = s.size();
        string out = "";
        reverse_substrings(s, out, 0, n-1, false);
        return out;
    }

    string reverseParentheses(string s) {
        
        int n = s.size();

        stack<int> parenthesis;
        unordered_map<int,int> match;

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                parenthesis.push(i);
            } else if (s[i] == ')') {
                int left_index = parenthesis.top();
                match[i] = left_index;
                match[left_index] = i;
                parenthesis.pop();
            }
        }

        string out = "";
        int offset = 1;

        for(int i = 0; i < n && i >= 0; i += offset) {

            if(s[i] == '(' || s[i] == ')') {
                i = match[i];
                offset = -offset;
            } else {
                out += s[i];
            }

        }

        return out;

    }

};
int main() {

    Solution s;

    string str = "(u(love)i)";
    cout << s.reverseParentheses(str) << '\n';

    string str2 = "(ed(et(oc))el)";
    cout << s.reverseParentheses(str2) << '\n';

    string str3 = "a(bcdefghijkl(mno)p)q";
    cout << s.reverseParentheses(str3) << '\n';

    return 0;
}