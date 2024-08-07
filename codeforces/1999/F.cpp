#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll MOD = 1e9 + 7;

ll comb(int n, int k) {

    if (k > n) { 
        return 0;
    }

    if (k == 0 || k == n) { 
        return 1;
    }

    ll res = 1;
    for (int i = 1; i <= k; ++i) {
        res *= (n - i + 1) / i;
        res %= MOD;
    }

    return res;

}

void solve() {

    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for(ll &x : a) {
        cin >> x;
    }

    ll valid_subsequences = 0;
    ll min_ones = (k + 1) / 2; 

    for (int i = 0; i < n; ++i) {

        if (a[i] == 1) {

            int left = i;
            int right = n - i - 1;
            
            if (left >= min_ones - 1 && right >= k - min_ones) {
                ll curr_subsequences = (comb(left, min_ones - 1) % MOD) * (comb(right, k - min_ones) % MOD) % MOD;
                valid_subsequences = (valid_subsequences + curr_subsequences) % MOD;
            }

        }

    }

    cout << valid_subsequences << '\n';

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