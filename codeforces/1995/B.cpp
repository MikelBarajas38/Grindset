#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    ll n, m;
    cin >> n >> m;

    vector<ll> flowers(n);
    for(ll &petals : flowers) {
        cin >> petals;
    }

    sort(all(flowers), greater<ll>());

    ll current_petals = 0, max_petals = 0, l = 0;
    for(int r = 0; r < n; ++r) {

        current_petals += flowers[r];
        while(l <= r && (current_petals > m || flowers[l] - flowers[r] > 1)) {
            current_petals -= flowers[l];
            l++;
        }

        max_petals = max(max_petals, current_petals);

    }

    cout << max_petals << '\n';


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