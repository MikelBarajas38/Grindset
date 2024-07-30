#include <bits/stdc++.h>
using namespace std;

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

    int sum(int l, int r) {
        return sum(r) - sum(l-1); 
    }

};

class Solution {
public:
    int numTeams1(vector<int>& rating) {
        
        int n = rating.size();

        int count = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                for(int k = j + 1; k < n; ++k) {

                    if( (rating[i] < rating[j] && rating[j] < rating[k]) ||
                        (rating[i] > rating[j] && rating[j] > rating[k])) {
                            count++;
                    }

                }
            }
        }

        return count;

    }

    int numTeams(vector<int>& rating) {

        int max_rating = *max_element(rating.begin(), rating.end());

        FenwickTree left_bit(max_rating);
        FenwickTree right_bit(max_rating);

        for(int &current_rating : rating) {
            right_bit.update(current_rating - 1, 1);
        }

        int teams = 0;

        for(int &current_rating : rating) {

            right_bit.update(current_rating - 1, -1);

            int smaller_left = left_bit.sum(0, current_rating - 1);
            int smaller_right = right_bit.sum(0, current_rating - 1);
            int larger_left = left_bit.sum(current_rating - 1, max_rating - 1);
            int larger_right = right_bit.sum(current_rating - 1, max_rating - 1);

            teams += (smaller_left * larger_right + smaller_right * larger_left);

            left_bit.update(current_rating - 1, 1);

        }

        return teams;

    }

};

int main() {
    Solution s;
    vector<int> rating = {2,5,3,4,1};
    cout << s.numTeams(rating) << '\n';
}