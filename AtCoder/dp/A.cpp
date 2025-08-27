#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int get_min_cost(int i, int k, vector<int> &h, vector<int> &dp) {
    int min_cost = INT_MAX;
    for(int j = i - 1; j >= 0 && i - j <= k; j--) {
        int cost = dp[j] + abs(h[i] - h[j]);
        min_cost = min(min_cost, cost);
    }
    return min_cost;
}

void solve() {

    int n, k;
    cin >> n >> k;

    vector<int> h(n);

    for(int &hi : h) {
        cin >> hi;
    }

    vector<int> dp(n);

    dp[0] = 0;

    for(int i = 1; i < n; ++i) {
        dp[i] = get_min_cost(i, k, h, dp);
    }

    cout << dp[n-1] << '\n';

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