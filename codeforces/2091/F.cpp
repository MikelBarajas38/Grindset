#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MOD 998244353

void solve() {

    int n, m, d;
    cin >> n >> m >> d;

    vector<string> map(n);
    for(string &level : map) {
        cin >> level;
    }

    vector<vector<ll>> p(n, vector<ll>(m));

    for(int j = 0; j < m; ++j) {
        if(map[n-1][j] == 'X') {
            p[n-1][j] = 1;
        }
    }

    for(int i = n-1; i >= 0; --i) {

        vector<ll> level(m);

        vector<ll> levelps(m+1);
        for(int j = 0; j < m; ++j) {
            levelps[j + 1] = (levelps[j] + p[i][j]) % MOD;
        }

        for(int j = 0; j < m; ++j) {
            if(map[i][j] != 'X') continue;
            int l = max(0, j - d);
            int r = min(j + d, m);
            level[j] = (levelps[r] - levelps[l]) % MOD;
        }

        p[i] = level;

        if(i == 0) {
            break;
        }

        for(int j = 0; j < m; ++j) {
            levelps[j + 1] = (levelps[j] + p[i][j]) % MOD;
        }

        for(int j = 0; j < m; ++j) {
            if(map[i-1][j] != 'X') continue;
            int l = max(0, j - d);
            int r = min(j + d, m);
            p[i-1][j] = (levelps[r] - levelps[l]) % MOD;
        }

    }

    ll total = 0;
    for(ll &p : p[0]) {
        total = (total + p) % MOD;
    }

    cout << total << '\n';

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T;
    cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}