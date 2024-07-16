#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    int n, k;
    cin >> n >> k;

    /*
    int steps = 0;
    while(n > 1) {
        n -= (k - 1);
        steps++;
    }
    cout << steps << '\n';
    */

    cout << (n - 1 + (k - 2)) / (k - 1) << '\n';
 
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