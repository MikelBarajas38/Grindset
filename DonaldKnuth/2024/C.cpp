#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    
    int n, m, k;
    cin >> n >> m >> k;

    int ai = k / n;

    if(ai == 0 || (ai == k && ai >= m)) {
        cout << "N\n";
        return;
    }

    if(ai < m) {
        cout << "S ";
        for(int i = 0; i < n-1; ++i) {
            cout << ai << ' ';
        }
        cout << ai + 1 << '\n';
    } else {
        cout << "S ";
        for(int i = 0; i < n; ++i) {
            cout << 1 << ' ';
        }
        cout << '\n';
    }

}

int main() {
	//cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);

    int T;
    cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}