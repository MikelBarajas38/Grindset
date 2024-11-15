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

    vector<vector<ll>> m(2 * n - 1, vector<ll> (2 * n - 1));
    m[0][0] = 1;

    int lim = 2 * n - 1;

    for(int i = 1; i <= lim; ++i) {

        int lim2 = i < n ? i + 1 : i - n - 1;

        m[i][0] += m[i-1][0];
        for(int j = 1; j < lim2; ++j) {
            m[i][j] = m[i-1][j] + m[i-1][j-1];
        }

        vector<ll> prev = m[i];

        m[i][0] += prev[1];
        for(int j = 1; j < lim2; ++j) {
            m[i][j] += prev[j-1] + prev[j+1];
        }

    }

    return;

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