#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll MOD = 1e9 + 7;

ll mod_exp(ll base, ll exp) {

    ll result = 1;

    while(exp > 0) {

        if(exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }

    return result;

}

void solve() {
    
    int n;
    cin >> n;

    ll fact = 1;
    for(ll i = 2; i <= n; ++i) {
        fact = (fact % MOD * i % MOD) % MOD;
    }

    fact = mod_exp(fact, 2);
    ll power = mod_exp(2, 2 * n);

    cout << (fact % MOD * power % MOD) % MOD << '\n';

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