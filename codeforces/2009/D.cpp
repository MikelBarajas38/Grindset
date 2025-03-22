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

    ll y1 = 0, y0 = 0;
    vector<ll> x1s(n+1);
    vector<ll> x0s(n+1);

    for(int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        if(y == 1) {
            y1++;
            x1s[x]++;
        } else {
            y0++;
            x0s[x]++;
        }
    }

    ll col_xs = 0, triangles = 0;

    for(ll i = 0; i <= n; ++i) {

        if(x1s[i] && x0s[i]) {
            col_xs++;
        }

        if(i == 0 || i == n) {
            continue;
        }

        if(x1s[i] && x0s[i - 1] && x0s[i + 1 ]) {
            triangles++;
        }

        if(x0s[i] && x1s[i - 1] && x1s[i + 1]) {
            triangles++;
        }

    }

    triangles += (col_xs * (y1 + y0 - 2));

    cout << triangles << '\n';

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