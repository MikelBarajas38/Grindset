#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    
    ll N, P;
    cin >> N >> P;

    ll remaining = N - P;

    ll patterns = remaining / P;
    patterns -= (patterns % 2);

    ll back_space = remaining - patterns * P;
    if (back_space % P == 0) {
        back_space = 0;
    }
    
    cout << back_space << '\n';

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int T = 1;
    //cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}