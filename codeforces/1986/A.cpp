#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;

    int min_f = INT_MAX;
    for(int p = 0; p <= 10; p++) {
        int f = abs(x1 - p) + abs(x2 - p) + abs(x3 - p);
        min_f = min(min_f, f);
    }

    cout << min_f << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T;
    cin >> T;

    while(T--){
        solve();
    }

    return 0;
}