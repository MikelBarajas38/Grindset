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
    for(ll &x: a) {
        cin >> x;
    }

    vector<ll> max_pair;

    for(int i = 1; i < n; i++) {
        max_pair.push_back(max(a[i], a[i-1]));
    }

    cout << *min_element(all(max_pair)) - 1 << "\n";
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