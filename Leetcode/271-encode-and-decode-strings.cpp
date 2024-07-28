#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {

        string header = "";
        string body = "";

        for(const string &s : strs) {
            header += to_string(s.size()) + "#";
            body += s;
        }
        
        header += "/";
        return header + body;

    }

    vector<string> decode(string s) {

        vector<int> sizes;

        int i = 0;
        string curr_size = "";

        for(i = 0; i < s.size(); ++i) {

            if(s[i] == '/') {
                i++;
                break;
            } else if(s[i] == '#') {
                sizes.push_back(stoi(curr_size));
                curr_size = "";
            } else {
                curr_size += s[i];
            }

        }

        vector<string> words;
        int k = 0;
        string curr_str = "";
        
        for(; i < s.size() && k < sizes.size(); ++i) {

            while(k < sizes.size() && sizes[k] == 0) {
                words.push_back("");
                k++;
            }

            curr_str += s[i];
            
            if(curr_str.size() == sizes[k]) {
                words.push_back(curr_str);
                curr_str = "";
                k++;
            }

        } 

        while(k < sizes.size() && sizes[k] == 0) {
            words.push_back("");
            k++;
        }

        return words;  

    }
};

int main() {

    Solution s;

    vector<string> strs = {"hello", "world", "this", "is", "a", "test"};

    string encoded = s.encode(strs);
    vector<string> decoded = s.decode(encoded);

    cout << "Encoded: " << encoded << '\n';
    cout << "Decoded: ";
    for(string &s : decoded) {
        cout << s << " ";
    }
    cout << '\n';

    vector<string> strs2 = {""};
    string encoded2 = s.encode(strs2);
    vector<string> decoded2 = s.decode(encoded2);

    cout << "Encoded: " << encoded2 << '\n';
    cout << "Decoded: ";
    for(string &s : decoded2) {
        cout << s << " ";
    }
    cout << '\n';

    vector<string> strs3 = {"neet", "code", "love", "you"};
    string encoded3 = s.encode(strs3);
    vector<string> decoded3 = s.decode(encoded3);

    cout << "Encoded: " << encoded3 << '\n';
    cout << "Decoded: ";
    for(string &s : decoded3) {
        cout << s << " ";
    }
    cout << '\n';

    return 0;
}