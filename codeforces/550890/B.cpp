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

    vector<ll> piles(n);
    for(ll &s : piles) {
        cin >> s;
    }

    /*
    vector<int> prefix(n + 1);
    for(int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + piles[i];
    }
    */
    
    int l = 0, r = n - 1;
    while(l < r) {

        int m = (l + r) / 2;
        int range = m - l + 1;

        cout << "? " << range << ' ';

        ll expected_sum = 0;
        for(int i = l; i <= m; ++i) {
            expected_sum += piles[i];
            cout << i + 1 << ' ';
        }

        cout << '\n' << flush;

        ll real_sum;
        cin >> real_sum;

        if(real_sum == expected_sum) {
            l = m + 1;
        } else {
            r = m;
        }

    }

    cout << "! " << l + 1 << '\n' << flush;

}

int main() {
	//cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);

    int T;
    cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}