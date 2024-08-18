#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {

        int n = arrays.size();

        pair<int,int> smallest = {10001, -1};
        pair<int,int> second_smallest = {10001, -1};

        pair<int,int> biggest = {-10001, -1};
        pair<int,int> second_biggest = {-10001, -1};

        for(int i = 0; i < n; ++i) {

            vector<int> array = arrays[i];
            int small = array[0];
            int big = array[array.size() - 1];

            if(small <= smallest.first) {
                second_smallest = smallest;
                smallest = {small, i};
            } else if (small <= second_smallest.first) {
                second_smallest = {small, i};
            }

            if(big >= biggest.first) {
                second_biggest = biggest;
                biggest = {big, i};
            } else if (big >= second_biggest.first) {
                second_biggest = {big, i};
            }
            
        }

        if(smallest.second != biggest.second) {
            return biggest.first - smallest.first; 
        } else {
            return max(biggest.first - second_smallest.first, second_biggest.first - smallest.first);
        }
        
    }
};

int main() {

    Solution s;
    

}
