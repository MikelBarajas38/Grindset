class Solution {
public:

    int passThePillow(int n, int time) {
        
        int len = n + (n - 2);
        int period = time % len;

        if(period < n) {
            return period + 1;
        } else {
            return n - (period - n + 1);
        }

    }

    int passThePillow1(int n, int time) {

        int curr = 1, d = 1;
        for(int i = 0; i < time; ++i) {
            curr += d;
            if(curr == n) d = -1;
            else if (curr == 1) d = 1;
        }

        return curr;

    }
};