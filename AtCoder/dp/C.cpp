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

    vector<vector<int>> activity(3, vector<int>(n));

    for(int i = 0; i < n; ++i) {
        cin >> activity[0][i] >> activity[1][i] >> activity[2][i];
    }

    vector<vector<int>> dp(3, vector<int>(n + 1));

    dp[0][1] = activity[0][0];
    dp[1][1] = activity[1][0];
    dp[2][1] = activity[2][0];

    for(int i = 2; i <= n; ++i) {
        for(int ca = 0; ca < 3; ca++) {
            int most_fun = 0;
            for(int a = 0; a < 3; a++) {
                int fun = dp[a][i-1] + activity[ca][i-1];
                if(a != ca && fun > most_fun) {
                    most_fun = fun;
                }
            }
            dp[ca][i] = most_fun;
        }
    }

    cout << max({dp[0][n], dp[1][n], dp[2][n]})<< '\n';

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