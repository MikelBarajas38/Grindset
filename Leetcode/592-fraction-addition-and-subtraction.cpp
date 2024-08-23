#include <bits/stdc++.h>
using namespace std;

class Solution {


    bool is_digit(char c) {
        return c >= '0' && c <= '9';
    }

public:
    string fractionAddition(string expression) {

        vector<int> numerator;
        vector<int> denominator;

        if(expression[0] != '-') {
            expression = "+" + expression; 
        }

        int n = expression.size(), sign = 1, i = 0;
        string x;

        while(i < n) {

            sign = (expression[i] == '+') ? 1 : -1;
            i++; // '+' or '-'

            x.clear();
            while(is_digit(expression[i])) {
                x += expression[i];
                i++;
            }
            numerator.push_back(sign * stoi(x));
            i++; // '/'

            x.clear();
            while(i < n && is_digit(expression[i])) {
                x += expression[i];
                i++;
            }
            denominator.push_back(stoi(x));

        }

        int lcm = 1;
        for(int &d : denominator) {
            lcm = d * lcm / gcd(d, lcm);
        }

        int fractions = numerator.size();
        int final_num = 0;
        for(int i = 0; i < fractions; ++i) {
            final_num += lcm * numerator[i] / denominator[i];
        }

        int g = gcd(final_num, lcm);

        return to_string(final_num / g) + "/" + to_string(lcm / g);
        
    }
};

int main() {
    Solution s;
    cout << s.fractionAddition("-1/2+1/2") << '\n';
    cout << s.fractionAddition("-1/2+1/2+1/3") << '\n';
    cout << s.fractionAddition("1/3-1/2") << '\n';
    cout << s.fractionAddition("5/3+1/3") << '\n';
    return 0;
}