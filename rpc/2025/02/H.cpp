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

    // n = (x)(x+1)/2
    // 2n = x^2 + x
    // 0 = x^2 + x - 2n

    ll x1 = (-1 + sqrt(1 + 4 * 2 * n)) / 2;
    ll x2 = (-1 - sqrt(1 + 4 * 2 * n)) / 2;

    cout << max(x1, x2) << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T = 1;
    //cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}