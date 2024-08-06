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

    ll max_odd = 0;
    priority_queue<ll> evens;
    for(int i = 0; i < n; i++) {

        ll x;
        cin >> x;

        if(x % 2 == 0) {
            evens.push(-x);
        } else {
            max_odd = max(max_odd, x);
        }

    }

    if(max_odd == 0) {
        cout << 0 << '\n';
        return;
    }

    ll ans = evens.size();
    while(!evens.empty()) {

        ll x = -evens.top();
        evens.pop();

        if(x > max_odd) {
            ans ++;
            break;
        }

        max_odd += x;

    }

    cout << ans << '\n';

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