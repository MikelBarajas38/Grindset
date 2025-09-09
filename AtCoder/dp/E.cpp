#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    ll N, W;
    cin >> N >> W;

    vector<ll> value(N), weight(N);
    ll max_value = 0;

    for(int i = 0; i < N; ++i) {
        cin >> weight[i] >> value[i];
        max_value += value[i];
    }

    vector<ll> dp(max_value + 1, INT_MAX);
    dp[0] = 0;

    for(ll i = 0; i < N; ++i) {
        for(ll x = max_value; x >= value[i]; x--) {
            if(dp[x - value[i]] == -1) continue;
            dp[x] = min(dp[x], dp[x- value[i]] + weight[i]);
        }
    }

    for(ll x = max_value; x >= 0; x--) {
        if(dp[x] <= W) {
            cout << x << '\n';
            break;
        }
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