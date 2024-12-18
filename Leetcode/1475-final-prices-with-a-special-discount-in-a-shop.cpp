class Solution {
public:

    vector<int> finalPrices1(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> final_prices(n);

        for(int i = n - 1; i >= 0; i--) {
            final_prices[i] = prices[i];
            for(int j = i + 1; j < n; j++) {
                if(prices[j] <= final_prices[i]) {
                    final_prices[i] -= prices[j];
                    break;
                }
            }
        }

        return final_prices;

    }

    vector<int> finalPrices2(vector<int>& prices) {
        
        int n = prices.size();
        stack<pair<int, int>> s;

        for(int i = 0; i < n; i++) {
            
            while(!s.empty() && s.top().first >= prices[i]) {
                prices[s.top().second] -= prices[i];
                s.pop();
            }

            s.push({prices[i], i});

        }

        return prices;

    }

    vector<int> finalPrices(vector<int>& prices) {
        
        int n = prices.size();
        stack<int> s;

        vector<int> final_prices = prices;

        for(int i = 0; i < n; i++) {
            
            while(!s.empty() && prices[s.top()] >= prices[i]) {
                final_prices[s.top()] -= prices[i];
                s.pop();
            }

            s.push(i);

        }

        return final_prices;

    }
};