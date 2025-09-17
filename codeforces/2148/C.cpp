#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/*

0 0
2 1
4 0


 0  1 2 3 4
 0 x 1 x 0


0 1 2 3 4
0 0


*/

void solve() {

    int n, m;
    cin >> n >> m;

    vector<int> mreq(n+1);
    vector<int> preq(n+1);
    for(int i = 1; i <= n; ++i) {
        cin >> mreq[i] >> preq[i];
    }

    int moves = 0;
    for(int i = 1; i <= n; ++i) {
        int timeframe = mreq[i] - mreq[i-1];
        if(timeframe % 2 == 0) {
            timeframe -= (preq[i] != preq[i-1]);
        } else {
            timeframe -= (preq[i] == preq[i-1]);
        }
        moves += timeframe;
    }

    int rem = m - mreq[n];

    cout << moves + rem << '\n';

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