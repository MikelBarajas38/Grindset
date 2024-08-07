#include <bits/stdc++.h>
using namespace std;

class Solution {

    unordered_map<int, string> ones_to_string = {
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"}
    };

    unordered_map<int, string> tens_to_string = {
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"}
    };

    unordered_map<int, string> scale = {
        {0, ""},
        {1, "Thousand"},
        {2, "Million"},
        {3, "Billion"}
    };

    // token is a three digit number
    string get_string(int token) {

        int hundreds = token / 100;
        int tens = (token % 100) / 10;
        int ones = token % 10;

        string result = "";

        if(hundreds) {
            result += ones_to_string[hundreds] + " Hundred";
        }

        if(tens) {

            if(hundreds) {
                result += " ";
            }

            if(tens == 1) {
                result += tens_to_string[tens * 10 + ones];
                return result;
            } else {
                result += tens_to_string[tens * 10];
            }

        }

        if(ones) {

            if(hundreds || tens) {
                result += " ";
            }

            result += ones_to_string[ones];
        }

        return result;

    }


public:
    string numberToWords(int num) {
        
        string number = "";

        if(num == 0) {
            return "Zero";
        }

        int token_counter = 0;
        while(num > 0) {

            int token = num % 1000;
            num /= 1000;

            if(!token) {
                token_counter++;
                continue;
            }

            string token_string = get_string(token);

            if(token_counter) {
                token_string += " " + scale[token_counter] + " ";
            }

            number = token_string + number;

            token_counter++;

        }

        // trim
        while(number.back() == ' '){
            number.pop_back();
        }

        return number;

    }
};

int main() {
    Solution s;
    cout << s.numberToWords(123) << '\n';
    return 0;
}