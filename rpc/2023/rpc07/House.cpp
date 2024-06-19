#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct FenwickTree {
    vector<ll> bit;  
    ll n;

    FenwickTree(ll n) {
        this->n = n;
        bit.assign(n + 1, 0); 
    }

    FenwickTree(vector<ll> const &a) : FenwickTree(a.size()) {
        for (ll i = 0; i < a.size(); i++)
            add(i + 1, a[i]);  
    }

    ll sum(ll r) {
        ll ret = 0;
        for (; r > 0; r -= (r & -r))
            ret += bit[r];
        return ret;
    }

    ll sum(ll l, ll r) {
        return sum(r) - sum(l - 1);
    }

    void add(ll idx, ll delta) {
        for (; idx <= n; idx += (idx & -idx))
            bit[idx] += delta;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n;
    cin >> n;
    vector<ll> houses(n);

    for(ll i=0; i<n; ++i) {
        cin >> houses[i];
    }

    FenwickTree tree(houses);

    ll t;
    cin >> t;

    for(ll i=0; i<t; ++i) {
        char op;
        cin >> op;

        if(op == 'U') {
            ll j, v;
            cin >> j >> v;
            tree.add(j, v);  
        } else {
            ll l, r;
            cin >> l >> r;
            cout << tree.sum(l, r) << "\n"; 
        }
    }

    return 0;
}