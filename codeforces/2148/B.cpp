#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<int> a(n);
    for(int &x : a) {
        cin >> x;
    }

    vector<int> b(m);
    for(int &x : b) {
        cin >> x;
    }

    cout << n + m << '\n';

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