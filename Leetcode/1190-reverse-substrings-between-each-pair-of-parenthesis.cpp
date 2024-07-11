#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

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
    cout << s.reverseParentheses(str) << endl;

    string str2 = "(ed(et(oc))el)";
    cout << s.reverseParentheses(str2) << endl;

    string str3 = "a(bcdefghijkl(mno)p)q";
    cout << s.reverseParentheses(str3) << endl;

    return 0;
}