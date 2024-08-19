#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    int nthUglyNumber(int n) {

        vector<long long> factors = {2, 3, 5};

        priority_queue<long long, vector<long long>, greater<long long>> q;
        unordered_set<long long> used;

        q.push(1);
        used.insert(1);

        long long nth_ugly_number = 1;
        
        for(int i = 1; i < n; ++i) {

            nth_ugly_number = q.top();
            q.pop();
            
            for(long long &f : factors) {
                long long next = nth_ugly_number * f;
                if(!used.count(next)) {
                    q.push(next);
                    used.insert(next);
                }
            }

        }

        return q.top();
        
    }
};

int main() {

    Solution s;

    cout << s.nthUglyNumber(27) << '\n';

}