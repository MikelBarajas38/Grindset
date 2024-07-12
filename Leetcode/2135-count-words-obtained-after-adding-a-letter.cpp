#include <bits/stdc++.h>
using namespace std;

/*

    tack
    
    {t: 1, a: 1, c: 1, k: 1}

    ant


*/

class Solution {
public:

    vector<int> get_vec(string &word) {
        vector<int> letter_count(26, 0);
        for(char &c : word) {
            letter_count[c - 'a']++;
        }
        return letter_count;
    }

    int wordCountBad(vector<string>& startWords, vector<string>& targetWords) { //TLE

        int n = targetWords.size(), m = startWords.size();

        vector<vector<int>> target_letter_count;
        for(string &word : targetWords) {
            target_letter_count.push_back(get_vec(word));
        }

        vector<vector<int>> start_letter_count;
        for(string &word : startWords) {
            start_letter_count.push_back(get_vec(word));
        }

        int possible_count = 0;
        for(int t = 0; t < n; t++) {

            for(int s = 0; s < m; s++) {

                int valid = true;
                int diffs = 0;

                for(int i = 0; i < 26; i++) {
                    if(target_letter_count[t][i] != start_letter_count[s][i]) {

                        diffs++;
                        if(diffs > 1 || target_letter_count[t][i] - start_letter_count[s][i] != 1) {
                            valid = false;
                            break;
                        }

                    }
                } 

                if(valid && diffs == 1) {
                    possible_count++;
                    break;
                }

            }

        }

        return possible_count;
        
    }

    bitset<26> get_bit(const string &word) {
        bitset<26> bits;
        for (char c : word) {
            bits.set(c - 'a');
        }
        return bits;
    }

    int wordCount1(vector<string>& startWords, vector<string>& targetWords) {

        int possible_count = 0;

        unordered_map<bitset<26>, int> target_letter_count;
        for(string &word : targetWords) {
            target_letter_count[get_bit(word)]++;
        }

        for(string &word : startWords) {
            bitset<26> bits = get_bit(word);
            for(int i = 0; i < 26; i++) {
                if(!bits.test(i)) {
                    bits.set(i);
                    if(target_letter_count.count(bits) && target_letter_count[bits] > 0) {
                        possible_count += target_letter_count[bits];
                        target_letter_count[bits] = 0;
                    }
                    bits.reset(i);
                }
            }
        }

        return possible_count;

    }

    int wordCount(vector<string>& startWords, vector<string>& targetWords) {

        int possible_count = 0;

        unordered_set<bitset<26>> start_letter_count;
        for(string &word : startWords) {
            start_letter_count.insert(get_bit(word));
        }

        for(string &word : targetWords) {
            bitset<26> bits = get_bit(word);
            for(int i = 0; i < 26; i++) {
                if(bits.test(i)) {
                    bits.reset(i);
                    if(start_letter_count.count(bits)) {
                        possible_count++;
                        break;
                    }
                    bits.set(i);
                }
            }
        }

        return possible_count;
        
    }
};

int main() {
    Solution s;

    vector<string> startWords3 = {"ab"}; 
    vector<string> targetWords3 = {"abc","abd", "cba"};
    cout << s.wordCount(startWords3, targetWords3) << '\n';

    vector<string> startWords = {"ant","act","tack"};
    vector<string> targetWords = {"tack","act","acti"};
    cout << s.wordCount(startWords, targetWords) << '\n';

    vector<string> startWords2 = {"g","vf","ylpuk","nyf","gdj","j","fyqzg","sizec"};
    vector<string> targetWords2 = {"r","am","jg","umhjo","fov","lujy","b","uz","y"};
    cout << s.wordCount(startWords2, targetWords2) << '\n';
    return 0;
}