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

    int past_home = -1, past_away = -1;
    for(int i = 0; i < n; ++i) {

        int home, away;
        cin >> home >> away;

        if(home < past_home || away < past_away) {
            cout << "no\n";
            return;
        }

        past_home = home;
        past_away = away;

    }

    cout << "yes\n";

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