class Solution {

    string get_signature(string s) {

        vector<int> count(26);
        for(char &c : s) {
            count[c - 'a']++;
        }

        string signature = "";
        for(char c = 'a'; c <= 'z'; ++c) {
            signature += c;
            signature += to_string(count[c - 'a']);
        }
        
        return signature;

    }

public:
    vector<vector<string>> groupAnagrams1(vector<string>& strs) {

        unordered_map<string, vector<string>> anagram_groups;

        for(string &s : strs) {
            anagram_groups[get_signature(s)].push_back(s);
        }

        vector<vector<string>> grouped_words;
        for(auto &[signature, word_list] : anagram_groups) {
            grouped_words.push_back(word_list);
        }

        return grouped_words;
        
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> anagram_groups;

        for(string &s : strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            anagram_groups[sorted].push_back(s);
        }

        vector<vector<string>> grouped_words;
        for(auto &[signature, word_list] : anagram_groups) {
            grouped_words.push_back(word_list);
        }

        return grouped_words;

    }

};