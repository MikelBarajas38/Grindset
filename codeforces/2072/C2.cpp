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

    ll lsz = ~(x) & (x+1);
    ll MEX = lsz - 1;

    vector<ll> key(n, 0);
    ll running_or = 0;

    for(ll i = 0; i <= MEX && i < n; ++i) {
        key[i] = i;
        running_or |= i;
    }

    if(running_or != x) {
        key[n-1] = x;
    }

    for(ll num : key) {
        cout << num << ' ';
    }
    cout << '\n';

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
