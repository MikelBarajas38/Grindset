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

    int ones = 0, zeros = 0;
    for(int i = 0; i < 2 * n; i++) {

        int x;
        cin >> x;

        if(x == 1) {
            ones++;
        } else {
            zeros++;
        }

    }

    int max_on = min(ones, zeros);
    int min_on = ones % 2;

    cout << min_on << ' ' << max_on << '\n';

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