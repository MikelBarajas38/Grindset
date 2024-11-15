#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    
    int n, r;
    cin >> n >> r;

    int extra = 0, happy = 0;
    for(int i = 0; i < n; i++) {
        int family;
        cin >> family;
        r -= (family / 2);
        happy += (family / 2);
        extra += (family % 2);
    }

    happy *= 2;

    if(extra) {
        if(extra > r) {
            happy += (r * 2 - extra);
        } else {
            happy += extra;
        }
    }

    cout << happy << '\n';

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