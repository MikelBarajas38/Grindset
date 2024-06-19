#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    string n;
    cin >> n;

    sort(rbegin(n), rend(n));

    string A = "0";
    string B = "0";

    A += n.substr(0, n.length() - 1);
    B += n.substr(n.length() - 1);

    ll ans = stol(A) + stol(B);
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