#include <bits/stdc++.h>
using namespace std;

/*

nums = [5,2,6,1]
indexes = [1,2,3,4]
        = [4,2,1,3]

sorted_indexes = [3,2,4,1]

       0 1 2 3 4
BIT = [0 0 0 0 0]

for each number x in reverse(n):

    i = sorted index of x
    smaller after self = sum(i)
    update(i, 1)

*/

class FenwickTree {

    vector<int> bit;
    int n;

public:

    FenwickTree(int size) {
        n = size + 1;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> A) : FenwickTree(A.size()) {
        for(int i = 0; i < A.size(); ++i) {
            update(i, A[i]);
        }
    }

    void update(int i, int x) {

        i++;

        while(i < n) {
            bit[i] += x;
            i += i & -i;
        }

    }

    int sum(int i) {

        i++;

        int ans = 0;
        while(i > 0) {
            ans += bit[i];
            i -= i & -i;
        }

        return ans;

    }  

};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {

        // Get sorted indexes

        int n = nums.size();

        vector<int> indexes;
        for(int i = 0; i < n; ++i) {
            indexes.push_back(i);
        }

        sort(indexes.begin(), indexes.end(), [&] (int l, int r) { 
            if(nums[l] == nums[r]) {
                return l < r;
            }
            return nums[l] < nums[r]; 
        } );

        vector<int> sorted_indexes(n);
        for(int i = 0; i < n; ++i) {
            sorted_indexes[indexes[i]] = i;
        }

        // get smaller elements after self

        FenwickTree bit(n);

        vector<int> smaller_elements_right(n);
        for(int i = n-1; i >= 0; --i) {
            smaller_elements_right[i] = bit.sum(sorted_indexes[i]);
            bit.update(sorted_indexes[i], 1);
        }

        return smaller_elements_right;

    }
};

int main() {

    Solution s;

    vector<int> nums = {26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
    vector<int> out = s.countSmaller(nums);

    for(int x : out) {
        cout << x << " ";
    }

    return 0;
}