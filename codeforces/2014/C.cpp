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
    ll mean = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mean += a[i];
    }

    if(n <= 2) {
        cout << -1 << "\n";
        return;
    }

    sort(all(a));

    ll mid = a[n / 2] * n;

    if(mid < mean / 2) {
        cout << 0 << "\n";
    } else {
        cout << mid * 2 - mean + 1 << "\n";
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