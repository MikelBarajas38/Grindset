#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int n = 8;

vector<string> board;
vector<char> cols(n);
vector<char> diag_lr(2 * n - 1);
vector<char> diag_rl(2 * n - 1);

void search(int r, int n) {

    if(r == n) {
        ans++;
        return;
    }

    for(int c = 0; c < n; ++c) {

        if(cols[c] || diag_rl[c + r] || diag_lr[r + n - 1 - c]) {
            continue;
        }

        if(board[r][c] == '*') {
            continue;
        }

        cols[c] = diag_rl[c + r] = diag_lr[r + n - 1 - c] = true;

        search(r + 1, n);

        cols[c] = diag_rl[c + r] = diag_lr[r + n - 1 - c] = false;

    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        board.push_back(s);
    }

    search(0, n);

    cout << ans << '\n';

    return 0;
}