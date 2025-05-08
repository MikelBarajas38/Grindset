#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

pair<ll, ll> find_ij(ll ti, ll tj, ll bi, ll bj, ll l, ll r, ll x) {

    if(ti == bi && tj == bj) {
        return {ti, tj};
    }

    ll diff = r - l + 1;
    ll idiff = bi - ti;
    ll jdiff = bj - tj;

    if(x <= l + diff/4 - 1) {
        return find_ij(ti, tj, ti + idiff/2, tj + jdiff/2, l, l + diff/4 - 1, x);
    } else if(x <= l + diff/2 - 1) {
        return find_ij(ti + idiff/2 + 1, tj + jdiff/2 + 1, bi, bj, l + diff/4, l + diff/2 - 1, x);
    } else if(x <= l + diff/4 * 3 - 1) {
        return find_ij(ti + idiff/2 + 1, tj, bi, tj + jdiff/2, l + diff/2, l + diff/4 * 3 - 1, x);
    } else {
        return find_ij(ti, tj + jdiff/2 + 1, ti + idiff/2, bj, l + diff/4 * 3, r, x);
    }

}

ll find_x(ll ti, ll tj, ll bi, ll bj, ll l, ll r, ll i, ll j) {

    if(l == r) {
        return l;
    }

    ll diff = r - l + 1;
    ll idiff = bi - ti;
    ll jdiff = bj - tj;

    if(i <= ti + idiff/2 && j <= tj + jdiff/2) {
        return find_x(ti, tj, ti + idiff/2, tj + jdiff/2, l, l + diff/4 - 1, i, j);
    } else if(i > ti + idiff/2 && j > tj + jdiff/2) {
        return find_x(ti + idiff/2 + 1, tj + jdiff/2 + 1, bi, bj, l + diff/4, l + diff/2 - 1, i, j);
    } else if(i > ti + idiff/2 && j <= tj + jdiff/2) {
        return find_x(ti + idiff/2 + 1, tj, bi, tj + jdiff/2, l + diff/2, l + diff/4 * 3 - 1, i, j);
    } else {
        return find_x(ti, tj + jdiff/2 + 1, ti + idiff/2, bj, l + diff/4 * 3, r, i, j);
    }

}

void solve() {

    ll n, q;
    cin >> n >> q;

    ll s = pow(2ll, n);
    ll lim = s * s;

    while(q--) {

        string op;
        cin >> op;

        if(op[0] == '<') {
            ll x;
            cin >> x;
            auto coords = find_ij(1, 1, s, s, 1, lim, x);
            cout << coords.first << ' ' << coords.second << '\n';
        } else {
            ll i, j;
            cin >> i >> j;
            cout << find_x(1, 1, s, s, 1, lim, i, j) << '\n';

        }

    }

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