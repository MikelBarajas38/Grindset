#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll MOD = 1e9 + 7;
ll inv_2;

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

    ll N, K;
    cin >> N >> K;

    N = (N + 1) % MOD;
    K = (K + 1) % MOD; 

    // Triangles from base = N * (N + 1) / 2
    ll triangles_from_base = ((N % MOD)  * ((N + 1) % MOD)) % MOD;
    triangles_from_base = (triangles_from_base * inv_2) % MOD;
    
    ll all_triangles = (triangles_from_base * K) % MOD;

    cout << all_triangles << '\n';

}

int main() {

	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    inv_2 = mod_exp(2, MOD - 2);

    int T;
    cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}