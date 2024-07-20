#include <bits/stdc++.h>
using namespace std;

/*

rows:

0 0 0 0
1 1 1 1
2 2 2 2
3 3 3 3

cols:

0 1 2 3
0 1 2 3
0 1 2 3
0 1 2 3

diag_rl:

0 1 2 3
1 2 3 4
2 3 4 5
3 4 5 6

diag_lr:

3 2 1 0
4 3 2 1
5 4 3 2
6 5 4 3


*/

class Solution {

private:

    vector<int> rows;
    vector<int> cols;
    vector<int> diag_lr;
    vector<int> diag_rl;

    vector<vector<string>> res;

    vector<string> build_board(int n) {

        vector<string> board;
        
        for(int i = 0; i < n; ++i) {
            string line = string(n, '.');
            board.push_back(line);
        }

        for(int i = 0; i < n; ++i) {
            board[i][rows[i]] = 'Q';
        }

        return board;

    }

    void search(int r, int n) {

        if(r == n) {
            res.push_back(build_board(n));
            return;
        }

        for(int c = 0; c < n; ++c) {

            if(cols[c] || diag_rl[c + r] || diag_lr[r + n - 1 - c]) {
                continue;
            }

            cols[c] = diag_rl[c + r] = diag_lr[r + n - 1 - c] = 1;
            rows[r] = c;

            search(r + 1, n);

            cols[c] = diag_rl[c + r] = diag_lr[r + n - 1 - c] = rows[r] = 0;

        }

    }


public:
    vector<vector<string>> solveNQueens(int n) {
        
        rows.resize(n);
        cols.resize(n);
        diag_lr.resize(n + n-1);
        diag_rl.resize(n + n-1);

        search(0, n);

        return res;

    }
};

int main() {

    Solution s;
    vector<vector<string>> res = s.solveNQueens(4);

    for(auto board : res) {
        for(auto line : board) {
            cout << line << '\n';
        }
        cout << '\n';
    }

    return 0;
}