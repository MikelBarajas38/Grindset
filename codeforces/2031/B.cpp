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

    vector<int> p(n);
    for(int &x : p) {
        cin >> x;
    }

    for(int i = 0; i < n; i++) {

        int diff = p[i] - i - 1;
        int dir = diff > 0 ? 1 : -1;

        if(diff > 2) {
            cout << "NO\n";
            return;
        } else {
            for(int j = i; abs(j - i) <= abs(diff); j += dir) {
                if(abs(p[j] - p[i]) > 1) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    cout << "YES\n";

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