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

    vector<bool> sieve(n+1);

    int pairs = 0;

    for(ll x = 2; x <= n; x++) {
        if(sieve[x]) {
            continue;
        }
        pairs++;
        for (int u = 2*x; u <= n; u += x) {
            sieve[u] = true;
            pairs++;
        }
    }

    cout << pairs << '\n';

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