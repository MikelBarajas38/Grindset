class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int lowest_value = prices[0], max_profit = 0;

        for(int i = 1; i < n; ++i) {
            max_profit = max(max_profit, prices[i] - lowest_value);
            lowest_value = min(lowest_value, prices[i]);
        }

        return max_profit;
        
    }
};