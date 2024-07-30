#include <bits/stdc++.h>
using namespace std;

// Binary Indexed Tree (fenwick tree)

class NumArray {

    vector<int> bit;
    int n;

    int sum(int index) {

        ++index; // 1-based indexing

        int out = 0;
        while(index > 0) {
            out += bit[index];
            index -= index & -index;
        }

        return out;

    }

public:

    NumArray(vector<int>& nums) {

        n = nums.size() + 1;
        bit.assign(n, 0);

        for(int i = 0; i < n - 1; ++i) {
            update(i, nums[i]);
        }

    }
    
    void update(int index, int val) {

        int delta = val - sumRange(index, index);

        ++index; // 1-based indexing

        while(index < n) {
            bit[index] += delta;
            index += index & -index;
        }
        
    }
    
    int sumRange(int left, int right) {
    
        return sum(right) - sum(left - 1);

    }

};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main() {

    vector<int> nums = {1, 3, 5};
    NumArray* obj = new NumArray(nums);
    cout << obj->sumRange(0, 2) << '\n';
    obj->update(1, 2);
    cout << obj->sumRange(0, 2) << '\n';

    return 0;

}