#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWaterBottles1(int numBottles, int numExchange) {
        
        int consumedBottles = 0, emptyBottles = 0;

        while(numBottles > 0) {

            consumedBottles += numBottles;
            int availableBottles = numBottles + emptyBottles;
            numBottles = availableBottles / numExchange;
            emptyBottles = availableBottles % numExchange;

        }

        return consumedBottles;

    }

    // 1 consumed bottle -> 1/numExchange new bottles
    // 1/numExchange consumed bottle -> 1/numExchange^2 new Bottles
    // ...
    // B = numBottles, E = numExchange
    // B + B/E + B/E^2 + B/E^3 + ...
    // sum of a geometric series = a / 1 - r, 
    // where a = first term (B) and r = common ratio (1/E) if |r| < 1
    // sum = B / (1 - 1/E)
    //     = B * E / (E - 1)
    // this implies infinite Exchanges, ends up overshooting

    int numWaterBottlesBad(int numBottles, int numExchange) {

        return numBottles * numExchange / (numExchange - 1);

    }

    // cost of a new bottle = numExchange - 1
    int numWaterBottles(int numBottles, int numExchange) {

        return numBottles + (numBottles - 1) / (numExchange - 1);

    }
};

int main() {

    Solution s;
    cout << s.numWaterBottles(9, 3) << '\n';
    cout << s.numWaterBottles(15, 4) << '\n';

}