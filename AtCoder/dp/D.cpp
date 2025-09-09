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
    for(int i = 0; i < N; ++i) {
        cin >> weight[i] >> value[i];
    }

    vector<ll> dp(W+1);

    for(ll i = 0; i < N; ++i) {
        for(ll x = W; x >= weight[i]; x--) {
            dp[x] = max(dp[x], dp[x - weight[i]] + value[i]);
        }
    }

    cout << dp[W] << '\n';

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