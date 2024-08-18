#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        unordered_map<int, int> count = {{5, 0}, {10, 0}, {20, 0}};
        
        for(int &bill : bills) {

            int change = bill - 5;

            int curr_change_bill = 10;
            while(change > 0) {

                if(change < curr_change_bill || count[curr_change_bill] == 0) {
                    curr_change_bill /= 2;
                }

                if(count[curr_change_bill] == 0) {
                    return false;
                }

                change -= curr_change_bill;
                count[curr_change_bill]--;

            }

            count[bill]++;

        }

        return true;
        
    }
};

int main() {

    Solution s;
    vector<int> bills = {5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5};
    cout << s.lemonadeChange(bills) << '\n';

    return 0;
}