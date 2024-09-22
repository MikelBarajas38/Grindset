#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {

	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    ll n, m;
    cin >> n >> m;

    ll fact_n = 0;
    for(ll x = 1; x * x <= n; ++x) {
        if(n % x == 0) {
            fact_n++;
            if(n / x != x) fact_n++;
        }
    }

    ll fact_m = 0;
    for(ll x = 1; x * x <= m; ++x) {
        if(m % x == 0) {
            fact_m++;
            if(m / x != x) fact_m++;
        }
    }

    cout << fact_m * fact_n << '\n';

    return 0;
}