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

    vector<ll> odd;
    vector<ll> even;
    for(int i = 0; i < n; ++i) {
        int d;
        cin >> d;
        if(d % 2 == 0) {
            even.push_back(d);
        } else {
            odd.push_back(d);
        }
    }

    if(odd.empty()) {
        cout << 0 << '\n';
        return;
    }

    ll max_cut = accumulate(all(even), 0ll);
    sort(all(odd));
    int odds = odd.size();
    for(int i = odds - 1; i >= odds / 2; --i) {
        max_cut += odd[i];
    }

    cout << max_cut << '\n';


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