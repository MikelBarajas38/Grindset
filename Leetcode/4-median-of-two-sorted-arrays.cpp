#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int get_mid(int l, int r) {
        return (l + r) / 2;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size(), m = nums2.size();
          
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << s.findMedianSortedArrays(nums1, nums2) << '\n';

    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << s.findMedianSortedArrays(nums3, nums4) << '\n';
    
    vector<int> nums5 = {1,3,5,6,7};
    vector<int> nums6 = {2,4,8};
    cout << s.findMedianSortedArrays(nums5, nums6) << '\n';

    vector<int> nums7;
    vector<int> nums8 = {1};
    cout << s.findMedianSortedArrays(nums7, nums8) << '\n';

    vector<int> nums9 = {1,2};
    vector<int> nums10 = {-1,3};
    cout << s.findMedianSortedArrays(nums9, nums10) << '\n';
}