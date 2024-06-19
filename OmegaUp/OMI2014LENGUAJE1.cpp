#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    ll m, n;
    cin >> m >> n;

    ll t;
    cin >> t;

    for(ll c = 0; c < t; c++) {

        ll k;
        cin >> k;

        ll i = k / m;
        ll j = k % m - 1;
        if(k % m == 0) {
            i--;
            j = m - 1;
        }
        
        //cout << i << ' ' << j << '\n';

        ll j1 = i;
        ll i1 = m - j - 1;
        //cout << j1 << ' ' << i1 << '\n';

        ll ans = i1 * n + j1 + 1;
        cout << ans << ' ';
    }

    return 0;
}