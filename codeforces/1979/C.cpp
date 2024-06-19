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

    vector<ll> a(n);
    for(ll &x : a) {
        cin >> x;
    }

    ll lcm = 1;
    for(ll &x : a) {
        lcm = lcm * x / __gcd(lcm, x);
    }

    ll acum = 0;
    for(ll &x : a) {
        acum += lcm / x;
    }

    if(acum >= lcm) {
        cout << -1 << "\n";
        return;
    }

    for(ll &x : a) {
        cout << lcm / x << " ";
    }
    cout << "\n";
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