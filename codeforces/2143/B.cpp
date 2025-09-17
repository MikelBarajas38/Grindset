#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {

    int n, k;
    cin >> n >> k;

    vector<ll> prod(n);
    for(ll &p : prod) {
        cin >> p;
    }

    vector<ll> disc(k);
    for(ll &d : disc) {
        cin >> d;
    }

    sort(rbegin(prod), rend(prod));
    sort(begin(disc), end(disc));

    ll min_cost = 0;
    ll j = 0;
    for(int i = 0; i < n; ++i) {
        if(j < k) {
            if (disc[j] > 1) {
                min_cost += prod[i];
                disc[j]--;
            } else {
                j++;
            }
        } else {
            min_cost += prod[i];
        }
    }

    cout << min_cost << '\n';

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