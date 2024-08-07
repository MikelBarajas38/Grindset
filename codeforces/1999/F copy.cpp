#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// interactive problem
void solve() {

    int l = 2, r = 1000;

    while(l < r) {

        int m = (l + r) / 2;
        cout << "? " << 1 << ' ' << m << endl; // endl flushes the output

        int ans;
        cin >> ans;

        if(ans == m) {
            l = m + 1;
        } else {
            r = m;
        }

    }

    cout << "! " << l << endl;

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