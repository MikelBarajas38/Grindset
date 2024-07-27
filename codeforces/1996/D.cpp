#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    ll n, x;
    cin >> n >> x;

    ll ans = 0;
    for(ll a = 1; a <= n && a <= x; a++) {
        for(ll b = 1; b * a <= n && a + b <= x ; b++) {
            
            ll c1 = x - a - b;
            ll c2 = (n - (a * b)) / (a + b);

            ll c = min(c1, c2);
            ans += c;

        }
    }

    cout << ans << '\n';

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