#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> sortPeople1(vector<string>& names, vector<int>& heights) {

        int n = names.size();
        vector<pair<int, string>> people;

        for(int i = 0; i < n; ++i) {
            people.emplace_back(heights[i], names[i]);
        }

        sort(people.begin(), people.end());
        
        vector<string> sorted_names;
        for(int i = 0; i < n; ++i) {
            sorted_names.push_back(people[n - i - 1].second);
        }

        return sorted_names;

    }

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        int n = names.size();
        vector<int> indexes(n, 0);
        for(int i = 0; i < n; ++i) {
            indexes[i] = i;
        }

        sort(indexes.begin(), indexes.end(), [&](int l, int r){ return heights[l] > heights[r]; });

        vector<string> sorted_names;
        for(int i = 0; i < n; ++i) {
            sorted_names.push_back(names[indexes[i]]);
        }

        return sorted_names;

    }
};

int main() {
    Solution s;
    vector<string> names = {"Mary", "John", "Emma"};
    vector<int> heights = {180, 165, 170};
    vector<string> sorted_names = s.sortPeople(names, heights);
    for(string &name : sorted_names) {
        cout << name << " ";
    }
    cout << endl;
}