#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    string s,t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    vector<int> dp(n + 1, -1);
    vector<int> prev(n + 1);
    dp[0] = 0;
    prev[0] = -1;

    for(int i = 0; i < m; ++i) {

        int max_i = 0;
        int max_size = dp[0];

        for(int j = 0; j < n; ++j) {

            if(t[i] == s[j] && dp[j + 1] < max_size + 1) {
                dp[j + 1] = max_size + 1;
                prev[j + 1] = max_i;
            } else if (dp[j + 1] > max_size) {
                max_size = dp[j + 1];
                max_i = j + 1;
            }

        }

    }

    int max_i = 0, max_size = 0;
    for(int i = 1; i <= n; ++i) {
        if(dp[i] > max_size) {
            max_size = dp[i];
            max_i = i;
        }
    }

    string ans = "";
    while(prev[max_i] != -1) {
        ans += s[max_i - 1];
        max_i = prev[max_i];
    }

    reverse(all(ans));

    cout << ans << '\n';

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