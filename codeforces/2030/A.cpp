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
    
    int min_val = INT_MAX;
    int max_val = -1;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        min_val = min(min_val, x);
        max_val = max(max_val, x);
    }

    cout << (max_val - min_val) * (n - 1) << '\n';

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