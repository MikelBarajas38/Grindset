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

    vector<string> grid(n);
    for(string &line : grid) {
        cin >> line;
    }

    for(int i = 0; i < n; i += k) {
        for(int j = 0; j < n; j += k) {
            cout << grid[i][j];
        }
        cout << '\n';
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