#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    
    ll x, m;
    cin >> x >> m;

    ll count = 0, lim = min(2 * x + 1, m);
    for(ll y = 1; y <= lim; ++y) {
        ll xor_xy = x ^ y;
        if(xor_xy % x == 0 || xor_xy % y == 0) {
            count++;
        }
    }

    cout << count << '\n';

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