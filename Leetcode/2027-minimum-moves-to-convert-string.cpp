class Solution {
public:
    int minimumMoves(string s) {
        
        int n = s.size(), moves = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == 'X') {
                i += 2;
                moves++;
            }
        }

        return moves;

    }
};