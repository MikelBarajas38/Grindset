class Solution {
public:
    bool isAnagram1(string s, string t) {

        unordered_map<char,int> s_freq;

        for(char &c : s) {
            s_freq[c]++;
        }

        for(char &c : t) {
            
            if(!s_freq.count(c)) {
                return false;
            }

            s_freq[c]--;

            if(s_freq[c] == 0) {
                s_freq.erase(c);
            }

        }

        return s_freq.size() == 0;
        
    }

    bool isAnagram(string s, string t) { 

        vector<int> word_set(26);

        for(char &c : s) {
            word_set[c - 'a']++;
        }

        for(char &c : t) {
            word_set[c - 'a']--;
        }

        for(int i = 0; i < 26; ++i) {
            if(word_set[i] != 0) {
                return false;
            }
        }

        return true;

    }
};