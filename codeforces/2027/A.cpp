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

    int max_w = 0, max_h = 0;
    for(int i = 0; i < n; i++) {
        int w, h;
        cin >> w >> h;
        max_w = max(max_w, w);
        max_h = max(max_h, h);
    }

    cout << 2 * (max_w + max_h) << "\n";
    
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