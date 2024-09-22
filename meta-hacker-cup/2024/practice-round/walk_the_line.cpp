#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int T) {
    
    ll n, k;
    cin >> n >> k;

    vector<ll> times(n);
    for(ll &s : times) {
        cin >> s;
    }

    ll min_time = *min_element(all(times));
    ll trips_needed = max((n - 2) * 2 + 1, 1LL);

    cout << "Case #" << T << ": ";
    if(min_time * trips_needed <= k) {
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

    for(int i = 1; i <= T; i++) {
        solve(i);
    }

    return 0;
}