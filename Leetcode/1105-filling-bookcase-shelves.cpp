#include <bits/stdc++.h>
using namespace std;

class Solution {

    int get_height(vector<vector<int>>& books, vector<vector<int>> &dp, int shelf_width, int remaining_width, int shelf_height, int i) {

        int height = books[i][1];
        int width = books[i][0];

        if(dp[i][remaining_width] != 0) {
            return dp[i][remaining_width];
        }

        if(i == books.size() - 1) {
            
            // option 1: place book in new shelf
            int new_shelf = shelf_height + height;

            // option 2: place in the same shelf
            int same_shelf = INT_MAX;
            if(remaining_width >= width) {
                same_shelf = max(shelf_height, height);
            }

            dp[i][remaining_width] = min(new_shelf, same_shelf);
            return dp[i][remaining_width];

        }

        // option 1: place book in new shelf
        int new_shelf = shelf_height + get_height(books, dp, shelf_width, shelf_width - width, height, i + 1);

        // option 2: place in the same shelf
        int same_shelf = INT_MAX;
        if(remaining_width >= width) {
            same_shelf  = get_height(books, dp, shelf_width, remaining_width - width, max(shelf_height, height), i + 1);
        }

        dp[i][remaining_width] = min(new_shelf, same_shelf);
        return dp[i][remaining_width];

    }
    

public:

    int minHeightShelves1(vector<vector<int>>& books, int shelfWidth) {
        
        int n = books.size();
        vector<int> dp(n+1);

        dp[0] = 0;
        dp[1] = books[0][1];

        for(int i = 1; i <= n; ++i) {

            int remaining_width = shelfWidth - books[i - 1][0];
            int shelf_height = books[i - 1][1];
            dp[i] = dp[i - 1] + shelf_height;

            for(int j = i - 1; j > 0; --j) {
            
                remaining_width -= books[j - 1][0];
                if(remaining_width < 0) {
                    continue;
                }

                shelf_height = max(shelf_height, books[j - 1][1]);

                dp[i] = min(dp[i], dp[j-1] + shelf_height);

            }


        }

        return dp[n];

    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {

        vector<vector<int>> dp(books.size(), vector<int>(shelfWidth + 1 , 0));
    
        return get_height(books, dp, shelfWidth, shelfWidth, 0, 0);
    
    }
};

int main() {

    Solution s;
    vector<vector<int>> books = {{1,1},{2,3},{2,3}};
    int shelfWidth = 4;

    cout << s.minHeightShelves(books, shelfWidth) << '\n';

    return 0;
}