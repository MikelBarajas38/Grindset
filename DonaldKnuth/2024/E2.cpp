#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    
    int n;
    cin >> n;

    vector<vector<int>> m(n, vector<int>(n));
    vector<vector<int>> row_prefix(n + 1, vector<int>(n + 1));
    vector<vector<int>> column_prefix(n + 1, vector<int>(n + 1));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> m[i][j];
        }
    }

    for(int i = 1; i <= n; ++i) {

        for(int j = 1; j <= n; ++j) {
            row_prefix[i][j] = row_prefix[i-1][j];
        }

        for(int j = 1; j <= n; ++j) {
            row_prefix[i][m[i-1][j-1]]++;
        }

    }

    for(int j = 1; j <= n; ++j) {

        for(int i = 1; i <= n; ++i) {
            column_prefix[i][j] = column_prefix[i][j-1];
        }

        for(int i = 1; i <= n; ++i) {
            column_prefix[m[i-1][j-1]][j]++;
        }

    }

    int q;
    cin >> q;

    while(q--) {

        int i1, j1, i2, j2, c;
        cin >> i1 >> j1 >> i2 >> j2 >> c;

        int row_val = row_prefix[i2][c] - row_prefix[i1-1][c];
        int col_val = column_prefix[c][j2] - column_prefix[c][j1-1];

        cout << min(row_val, col_val) << '\n';

    }

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T = 1;
    //cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}