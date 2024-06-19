#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef int64_t ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll damage_output(ll t, vector<ll> &d, vector<ll> &c, ll &h) {
    ll total_damage = 0;

    for(int i = 0; i < d.size(); i++) {
        total_damage += d[i];
        total_damage = min(total_damage, h);
    }

    t--;

    for (int i = 0; i < d.size(); i++) {
        total_damage += (t / c[i] * d[i]);
        total_damage = min(total_damage, h);
    }

    return total_damage;
}

void solve() {

    ll h, n;
    cin >> h >> n;

    vector<ll> d(n);
    for(ll &x : d) {
        cin >> x;
    }

    vector<ll> c(n);
    for(ll &x : c) {
        cin >> x;
    }

    ll l = 1;
    ll r = 1e12;

    while (l < r) {
        ll m = l + (r - l) / 2;
        if (damage_output(m, d, c, h) >= h) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    cout << l << "\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}