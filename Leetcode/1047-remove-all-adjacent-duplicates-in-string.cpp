class Solution {
public:
    string removeDuplicates1(string s) {
        
        stack<char> helper;
        for(char &c : s) {
            if(!helper.empty() && helper.top() == c) {
                helper.pop();
            } else {
                helper.push(c);
            }
        }

        string ans = "";
        while(!helper.empty()) {
            ans += helper.top();
            helper.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }

    string removeDuplicates(string s) {
        
        string helper;
        for(char &c : s) {
            if(!helper.empty() && helper.back() == c) {
                helper.pop_back();
            } else {
                helper.push_back(c);
            }
        }
        return helper;
    }
    
};