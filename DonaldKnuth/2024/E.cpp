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

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> m[i][j];
        }
    }

    int q;
    cin >> q;

    while(q--) {

        int i1, j1, i2, j2, c;
        cin >> i1 >> j1 >> i2 >> j2 >> c;

        i1--; j1--; i2--; j2--;

        int ans = 0;
        for(int i = i1; i <= i2; ++i) {
            for(int j = j1; j <= j2; ++j) {
                if(m[i][j] == c) {
                    ans++;
                }
            }
        }

        cout << ans << '\n';

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