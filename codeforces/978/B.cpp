#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool could_finish(vector<ll> &cars, ll m, ll x) {
    

    return ops;
}

void solve() {
    
    ll n, x;
    cin >> n >> x; 

    vector<ll> cars(n);
    ll max_ops = 0;
    for(ll &car : cars) {
        cin >> car;
        max_ops += car;
    }

    sort(cars.rbegin(), cars.rend());

    ll l = 0, r = max_ops;
    while(l < r) {
        ll m = l + (r - l) / 2;
        
        ll ops = could_finish(cars, m, x);

        if(ops >= x) {
            l = m + 1;
        } else {
            r = m;
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