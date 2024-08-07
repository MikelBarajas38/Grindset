#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll max_val = 2 * 1e5 + 1;

vector<ll> dp(max_val, -1);
vector<ll> dp2(max_val, -1);

ll log3(ll x) {

    if (x == 0) {
        return 0;
    }

    if (dp[x] != -1) {
        return dp[x];
    }

    ll xd = x, ans = 0;
    while (xd > 0) {
        xd /= 3;
        ans++;
    }

    dp[x] = ans;

    return dp[x];

}

void solve() {

    ll l, r;
    cin >> l >> r;

    ll moves = dp2[r] - dp2[l - 1] + log3(l);
    
    cout << moves << '\n';

}

void init() {

    for (int i = 1; i <= max_val; ++i) {
        ll x = i;
        ll ans = 0;
        while (x > 0) {
            x /= 3;
            ans++;
        }
        dp[i] = ans;
        dp2[i] = dp2[i - 1] + dp[i];
    }

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    init();

    int T;
    cin >> T;

    while(T--) {
        solve();
    }
    return 0;

}