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

    vector<ll> seq(n);
    for(ll &x : seq) {
        cin >> x;
    }

    vector<ll> moves(n);
    moves[0] = 0;

    int ans = 0;
    for(int i = 1; i < n; i++) {
        ll curr = seq[i];
        ll prev = seq[i-1];

        if(curr == 1 && prev != 1) {
            cout << "-1\n";
            return;
        }

        while(curr < prev) {
            curr *= curr;
            moves[i]++;
        }

        moves[i] += moves[i-1];
        ans += moves[i];

    }


    cout << ans << '\n';

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