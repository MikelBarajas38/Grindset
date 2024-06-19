#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<ll> machines;

ll product_output(ll t) {
    ll total_output = 0;
    for(ll &m : machines) total_output += (t / m);
    return total_output;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    ll x, t;

    cin >> x >> t;

    machines.resize(x);
    for(ll &m : machines) cin >> m;
    
    ll l = 0;
    ll r = (ll) 10e20;

    while(l < r) {
        ll m = l + (r-l)/2;

        ll output = product_output(m);

        if(output >= t) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    if(product_output(l) < t) l++;

    cout << l << "\n";

    return 0;
}