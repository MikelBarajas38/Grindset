#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    
    ll n;
    cin >> n;

    vector<ll> a(n);
    ll expected_val = 0;
    for(ll &x : a) {
        cin >> x;
        expected_val += x;
    }  

    expected_val /= n;

    ll cost_odd = 0, cost_even = 0;
    for(ll i = 0; i < n; ++i) {
        ll diff = a[i] - expected_val;
        if(i % 2 == 0) {
            cost_even += diff;
        } else {
            cost_odd += diff;
        }
    }

    if(cost_odd == 0 && cost_even == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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