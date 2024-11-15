#include <bits/stdc++.h>
#include <euclid.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define OUT_OF_BOUNDS 10001

void solve() {
    
    int xs, ys, xt, yt, xp, yp;
    cin >> xs >> ys >> xt >> yt >> xp >> yp;

    int out_x_dir = (xs - xp) / abs(xs - xp);
    int in_x_dir = (xt - xp) / abs(xt - xp);

    vector<pair<int, int>> moves;

    moves.push_back({out_x_dir * OUT_OF_BOUNDS, ys});

    if(out_x_dir == in_x_dir) {
        moves.push_back({out_x_dir * OUT_OF_BOUNDS, yt});
    } else {
        moves.push_back({out_x_dir * OUT_OF_BOUNDS, OUT_OF_BOUNDS});
        moves.push_back({in_x_dir * OUT_OF_BOUNDS, OUT_OF_BOUNDS});
        moves.push_back({in_x_dir * OUT_OF_BOUNDS, yt});
    }

    cout << moves.size() << '\n';
    for(auto &[x, y] : moves) {
        cout << x << ' ' << y << '\n';
    }

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