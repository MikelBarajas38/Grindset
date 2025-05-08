#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool is_prime(ll x) {

    if(x < 2) {
        return false;
    }

    for(ll i = 2; i * i <= x; ++i) {
        if(x % i == 0) {
            return false;
        }
    }

    return true;
}

void solve() {

    ll x, k;
    cin >> x >> k;

    if((is_prime(x) && k == 1) || (x == 1 && k == 2)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }


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