
/*


1 2 1 1 1
  2 1 2 1
1 3 2 2 1

1 1 2
2 1 1
1 0 2


1 2 1 1 0 -1
1 3 2 2 1  1

1 2 1 1 1 1
1 1 2 1 2 3

1 2 1 1 2 3 =

2 4 3 3 2 1

*/

class Solution {

public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();
        vector<int> ltor(n, 1);
        for(int i = 1; i < n; ++i) {
            if(ratings[i] > ratings[i-1]) {
                ltor[i] += ltor[i-1];
            }
        }

        vector<int> rtol(n, 1);
        for(int i = n - 2; i >= 0; --i) {
            if(ratings[i] > ratings[i+1]) {
                rtol[i] += rtol[i+1];
            }
        }

        int min_candies = 0;
        for(int i = 0; i < n; ++i) {
            min_candies += max(ltor[i], rtol[i]);
        }

        return min_candies;

    }
};