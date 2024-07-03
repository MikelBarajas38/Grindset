class Solution {
public:

    vector<int> intersect2(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,int> nums1_count;
        for(int &x : nums1) {
            nums1_count[x]++;
        }

        vector<int> intersection;
        for(int &x : nums2) {
            if(nums1_count[x] > 0) {
                intersection.push_back(x);
                nums1_count[x]--;
            }
        }

        return intersection;

    }

    vector<int> intersect1(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int size1 = nums1.size(), size2 = nums2.size();

        vector<int> intersection;
        int p1 = 0, p2 = 0;
        while(p1 < size1 && p2 < size2) {
            if(nums1[p1] == nums2[p2]) {
                intersection.push_back(nums1[p1]);
                p2++;
                p1++;
            } else if(nums1[p1] < nums2[p2]) {
                p1++;
            } else {
                p2++;
            }
        }

        return intersection;

    }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        map<int,int> nums1_count;
        for(int &x : nums1) {
            nums1_count[x]++;
        }

        vector<int> intersection;
        for(int &x : nums2) {
            if(nums1_count[x] > 0) {
                intersection.push_back(x);
                nums1_count[x]--;
            }
        }

        return intersection;

    }
};