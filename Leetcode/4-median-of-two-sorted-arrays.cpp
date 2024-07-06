#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    double findValueInGivenPos(vector<int>& nums1, vector<int>& nums2, int goal) {
        
        int n = nums1.size(), m = nums2.size();
        int l1 = 0, r1 = n - 1, l2 = 0, r2 = m - 1, m1, m2;
        int x1, x2;

        while(l1 <= r1 && l2 <= r2) {

            m1 = (l1 + r1) / 2;
            m2 = (l2 + r2) / 2;
            
            x1 = nums1[m1];
            x2 = nums2[m2];

            if(goal > m1 + m2) {

                if(x1 > x2) {
                    l2 = m2 + 1;
                } else {
                    l1 = m1 + 1;
                }

            } else {

                if(x1 > x2) {
                    r1 = m1 - 1;
                } else {
                    r2 = m2 - 1;
                }

            }

        }

        if(r1 < l1) {
            return nums2[goal - l1];
        } else{
            return nums1[goal - l2];
        }


    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size(), m = nums2.size();

        /*
        if(n == 0) {
            return (m % 2) ? nums2[m/2] : (nums2[m/2] + nums2[m/2-1]) / 2.0;
        } else if(m == 0) {
            return (n % 2) ? nums1[n/2] : (nums1[n/2] + nums1[n/2-1]) / 2.0;
        }
        */

        int ml = (n + m - 1) / 2;
        double median1 = findValueInGivenPos(nums1, nums2, ml);

        int mr = (n + m) / 2;
        double median2 = findValueInGivenPos(nums1, nums2, mr);

        return ((n + m) % 2) ? median1 : (median1 + median2) / 2.0;

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