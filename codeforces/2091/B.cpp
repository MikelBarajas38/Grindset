#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    ll n, x;
    cin >> n >> x;

    ll strong_teams = 0;
    vector<ll> remaining(n);

    for(ll &sl : remaining) {
        cin >> sl;
    }

    sort(all(remaining));
    reverse(all(remaining));

    ll team_size = 1;

    for(int i = 0; i < n; i++) {

        ll current_level = team_size * remaining[i];

        if(current_level >= x) {
            strong_teams++;
            team_size = 1;
        } else {
            team_size++;
        }

    }

    cout << strong_teams << '\n';

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