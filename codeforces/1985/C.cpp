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

    ll sum = 0, max_val = 0;
    int good_arrays = 0;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;

        sum += x;
        max_val = max(max_val, x);

        if (sum - 2 * max_val == 0) {
            good_arrays++;
        }
    }

    cout << good_arrays << "\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}