#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    ll n, k, p;
    cin >> n >> k >> p;

    ll cont = (100 - p) * (n - k + 1) + p * (n - k + 1 + 3 + n + 1);
    ll back = (100 - p) * (1 + n - k + 1 + 3 + n + 1) + p * (1 + n - k + 1);
    ll rest = (100 - p) * (3 + n + 1) + p * (3 + n + 1);

    ll best = min({cont, back, rest});

    if(best == cont) {
        cout << "continue\n";
    } else if(best == back) {
        cout << "backspace\n";
    } else {
        cout << "restart\n";
    }

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