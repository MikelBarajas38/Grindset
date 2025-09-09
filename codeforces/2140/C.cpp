#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/*

    + - + - + -
    cost = 0

    1 2 3 4 5
    + - + - +
    9 9 9 9 9



*/

void solve() {

    int n;
    cin >> n;

    vector<ll> a(n);
    for(ll &x : a) {
        cin >> x;
    }

    ll initial_f = 0, best_a = 0, best_a_i = 1;
    for(int i = 0; i < n; ++i) {
        if(i % 2 == 0) {
            initial_f += a[i];
            if(best_a > a[i]) {
                best_a = a[i];
                best_a_i = i;
            }
        } else {
            initial_f -= a[i];
        }
    }

    ll best_free_move = (n-1) / 2 * 2;

    ll max_score = best_free_move + initial_f;

    ll best_neg_move = 0;
    for(ll i = 0; i < n; ++i) {
        if(i % 2 == 1) {
            ll score = initial_f + 2 * a[i] - 2 * best_a + abs(best_a_i - i);
            max_score = max(max_score, score);
        }
    }

    cout << max_score << '\n';

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